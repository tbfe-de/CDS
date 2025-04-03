#ifndef V4_ChainCounter_H
#define V4_ChainCounter_H

#include "ICounter.h"

namespace v4 {
class BaseCounter : public ICounter {
protected:
    const int range_;
    int value_;

public:
    BaseCounter(int range)
        : range_{range}, value_{range - 1}
    {/*empty*/}
    int GetValue() const override final  { return value_; }
    int Remaining() const override final ;
    void Step1() override final ;
    void StepN(int n) override final ;

private:
    // Customization points for derived class
    virtual int remains_above() const { return 0; }
    virtual bool step_above() { return false; }
};

class ChainCounter : public BaseCounter {
private:
    BaseCounter& next_;

public:
    ChainCounter(int range, BaseCounter& next)
        : BaseCounter{range}, next_{next}
    {/*empty*/}

private:
    int remains_above() const override;
    bool step_above() override;
}; // class
} // namespace
#endif // include guard
