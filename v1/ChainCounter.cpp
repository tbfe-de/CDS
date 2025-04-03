#include "ChainCounter.h"

using v1::ChainCounter;

void ChainCounter::Step1() {
    if (value_ != 0) --value_;
    else {
        if ((next_ != nullptr)
         && (next_->Remaining() > 0)) {
            next_->Step1();
            value_ = range_ - 1;
        }
    }
}

#if defined(USE_FAILING_AI_IMPLEMENTATION)
int ChainCounter::Remaining() const {
    int total = value_;
    if (next_) {
        total += (range_ - 1 - value_) * next_->range_ + next_->Remaining();
    }
    return total;
}
#elif defined(USE_IMPROVED_AI_IMPLEMENTATION)
int ChainCounter::Remaining() const {
    int remaining_above = next_ ? next_->Remaining() : 0;
    return remaining_above * range_ + value_;
}
#elif defined(USE_NON_RECURSIVE_AI_IMPLEMENTATION)
int ChainCounter::Remaining() const {
    int total = 0;
    int multiplier = 1;

    const ChainCounter* current = this;
    while (current) {
        total += current->value_ * multiplier;
        multiplier *= current->range_;
        current = current->next_;
    }

    return total;
}
#elif defined(USE_MY_OWN_IMPLEMENTATION)
int ChainCounter::Remaining() const {
    const int remaining_in_upper_stages = (next_ != nullptr)
                                            ? next_->Remaining()
                                            : 0;
    return range_*remaining_in_upper_stages + value_;
}
#else
#error "implementation to be used was not defined"
#endif

void ChainCounter::StepN(int distance) {
    while (distance-- > 0) Step1();
}
