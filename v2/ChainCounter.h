#ifndef V2_ChainCounter_H
#define V2_ChainCounter_H

namespace v2 {
class BaseCounter {
protected:
    const int range_;
    int value_;
public:
    BaseCounter(int range)
        : range_{range}, value_{range-1}
    {/*empty*/}
    auto GetValue() const { return value_; }
    virtual int Remaining() const { return value_; }
    virtual void Step1() { if (value_ > 0) --value_; }
    void StepN(int);
}; // class

class ChainCounter : public BaseCounter {
private:
    BaseCounter& next_;
public:
    ChainCounter(int range, BaseCounter& next)
        : BaseCounter{range}, next_{next}
    {/*empty*/}
    int Remaining() const override;
    void Step1() override;
}; // class
} // namespace

#endif // include guard
