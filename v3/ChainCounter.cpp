#include "ChainCounter.h"

using v3::BaseCounter;
using v3::ChainCounter;

int BaseCounter::Remaining() const {
    return value_ + range_ * remains_above();
}

#if defined(USE_FAILING_AI_IMPLEMENTATION)
void BaseCounter::Step1() {
    if (value_ > 0) {
        --value_;
    } else {
        step_above();
        value_ = range_ - 1;
    }
}
#elif defined(USE_IMPROVED_AI_IMPLEMENTATION)\
   || defined(USE_MY_OWN_IMPLEMENTATION)
void BaseCounter::Step1() {
    if (value_ > 0) {
        --value_;
    } else {
        if (step_above()) {
            value_ = range_ - 1;
        }
    }
}
#endif

void BaseCounter::StepN(int n) {
    for (int i = 0; i < n; ++i)
        Step1();
}

int ChainCounter::remains_above() const {
    return next_.Remaining(); // polymorphic via NVI
}

#if defined(USE_FAILING_AI_IMPLEMENTATION)
void ChainCounter::step_above() override {
    next_.Step1(); // polymorphic via NVI
}
#elif defined(USE_IMPROVED_AI_IMPLEMENTATION)
bool ChainCounter::step_above() override {
    int before = next_.Remaining();
    next_.Step1();
    int after = next_.Remaining();
    return after < before;
}
#elif defined(USE_MY_OWN_IMPLEMENTATION)
bool ChainCounter::step_above() {
    if (next_.Remaining()) {
        next_.Step1();
        return true;
    }
    return false;
}
#else
#error "implementation to be used must be defined"
#endif
