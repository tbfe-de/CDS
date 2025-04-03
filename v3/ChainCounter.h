#ifndef V3_ChainCounter_H
#define V3_ChainCounter_H

namespace v3 {
class BaseCounter {
protected:
    const int range_;
    int value_;

public:
    BaseCounter(int range)
        : range_{range}, value_{range - 1}
    {/*empty*/}
    int GetValue() const { return value_; }
    int Remaining() const;
    void Step1();
    void StepN(int n);

private:
    // Customization points for derived class
    virtual int remains_above() const { return 0; }
#if defined(USE_FAILING_AI_IMPLEMENTATION)
    virtual void step_above() {}
#elif defined(USE_IMPROVED_AI_IMPLEMENTATION)\
   || defined(USE_MY_OWN_IMPLEMENTATION)
    virtual bool step_above() { return false; }
#endif
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
#if defined(USE_FAILING_AI_IMPLEMENTATION)
    void step_above() override;
#elif defined(USE_IMPROVED_AI_IMPLEMENTATION)\
   || defined(USE_MY_OWN_IMPLEMENTATION)
    bool step_above() override;
#endif
}; // class
} // namespace
#endif // include guard
