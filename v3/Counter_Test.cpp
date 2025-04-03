#include "ChainCounter.h"

#include <cassert>  // assert (macro)
#include <iostream> // std::cout (global)
                    // std::endl (global)

int main() {
    using namespace v3;

    { // single (1-stage down counter)
    BaseCounter single{20};
    single.Step1();
    assert(single.GetValue() == 18);

    single.StepN(10);
    assert(single.GetValue() == 8);

    single.StepN(10);
    assert(single.GetValue() == 0);
    }
    { // twostage (2-stage down counter)
    BaseCounter hours{24};
    ChainCounter minutes{60, hours};
    assert(hours.GetValue() == 23);
    assert(minutes.GetValue() == 59);

    minutes.StepN(100);
    assert(hours.GetValue() == 22);
    assert(minutes.GetValue() == 19);
    }
    { // count down from 9 hours, 59 minutes, and 59 seconds
    BaseCounter hours{10};
    assert(hours.GetValue() == 9);
    assert(hours.Remaining() == 9);
    ChainCounter minutes{60, hours};
    assert(minutes.GetValue() == 59);
    assert(minutes.Remaining() == 59 + 9*60);
    ChainCounter seconds{60, minutes};
    assert(seconds.GetValue() == 59);
    assert(seconds.Remaining() == 59 + 59*60 + 9*60*60);

    seconds.StepN(9033);
    assert(hours.GetValue() == 7);
    assert(minutes.GetValue() == 29);
    assert(seconds.GetValue() == 26);

    seconds.StepN(seconds.Remaining()-1);
    assert(hours.GetValue() == 0);
    assert(minutes.GetValue() == 0);
    assert(seconds.GetValue() == 1);

    seconds.Step1();
    assert(hours.GetValue() == 0);
    assert(minutes.GetValue() == 0);
    assert(seconds.GetValue() == 0);

    seconds.Step1();
    assert(hours.GetValue() == 0);
    assert(minutes.GetValue() == 0);
    assert(seconds.GetValue() == 0);
    }

    std::cout << "** all tests passed **\n";
}
