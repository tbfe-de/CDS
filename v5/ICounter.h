#ifndef V4_ICounter_H
#define V4_ICounter_H

/*
Das Interface muss auch eine Template werden, und zwar:
*/

template<typename T>
class ICounter {
public:
    virtual ~ICounter() =default;
    virtual T GetValue() const =0;
    virtual T Remaining() const =0;
    virtual void Step1() =0;
    virtual void StepN(T) =0;
};

#endif // include guard
