#ifndef V1_ChainCounter_H
#define V1_ChainCounter_H

namespace v1 {
class ChainCounter {
private:
    const int range_;
    int value_;
    ChainCounter* next_;
public:
    ChainCounter(int range, ChainCounter* next = nullptr)
        : range_{range}, value_{range-1}, next_{next}
    {/*empty*/}
    auto GetValue() const { return value_; }
    int Remaining() const;
    void Step1();
    void StepN(int);
}; // class
} // namespace


#endif // include guard
