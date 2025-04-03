#include "ChainCounter.h"

#include <iostream> // std::cout (global)
#include <iomanip> // std::setw (global)

int main() {
    using namespace v2;

    BaseCounter hours{24};
    ChainCounter minutes{60, hours};
    ChainCounter seconds{60, minutes};

    std::cout.fill('0');
    int steps;
    while ((seconds.Remaining() > 0)
        && (std::cin >> steps)) {
        std::cout << std::setw(2) << hours.GetValue() << ':'
                  << std::setw(2) << minutes.GetValue() << ':'
                  << std::setw(2) << seconds.GetValue()
                  << " - stepping down " << steps << " from here...\n";
        seconds.StepN(steps);
    }
    std::cout << std::setw(2) << hours.GetValue() << ':'
                  << std::setw(2) << minutes.GetValue() << ':'
                  << std::setw(2) << seconds.GetValue()
                  << " - DONE\n";
}
