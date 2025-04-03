#include "ChainCounter.h"

using v2::BaseCounter;
using v2::ChainCounter;

void BaseCounter::StepN(int distance) {
    while (distance-- > 0) Step1();
}
void ChainCounter::Step1() {
    if (value_ > 0)
        BaseCounter::Step1();
    else if (next_.Remaining() > 0) {
        next_.Step1();
        value_ = range_-1;
    }
}

int ChainCounter::Remaining() const {
    int remaining_above = next_.Remaining();
    return remaining_above * range_ + value_;
}
