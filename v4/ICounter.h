#ifndef V4_ICounter_H
#define V4_ICounter_H

class ICounter {
public:
    virtual ~ICounter() =default;
    virtual int GetValue() const =0;
    virtual int Remaining() const =0;
    virtual void Step1() =0;
    virtual void StepN(int) =0;
};

#endif // include guard
