#include "ChainCounter.h"

using v4::BaseCounter;
using v4::ChainCounter;

int BaseCounter::Remaining() const {
    return value_ + range_ * remains_above();
}

void BaseCounter::Step1() {
    if (value_ > 0) {
        --value_;
    } else {
        if (step_above()) {
            value_ = range_ - 1;
        }
    }
}

void BaseCounter::StepN(int n) {
    for (int i = 0; i < n; ++i)
        Step1();
}

int ChainCounter::remains_above() const {
    return next_.Remaining(); // polymorphic via NVI
}

bool ChainCounter::step_above() {
    if (next_.Remaining()) {
        next_.Step1();
        return true;
    }
    return false;
}
