#ifndef V4_ChainCounter_H
#define V4_ChainCounter_H

#include "ICounter.h"


namespace v4 {
/*
 In BaseCounter soll der Wert des "Range" nicht mehr in
 einem `const Datenmember abgelegt werden, sondern ein
 Template-Argument werden. Darüber hinaus soll der Typ
 des Zählerstand (value_) durch ein Typ-Argument dieser
 Template variabel gehalten werden. In die spitzen Klammern
 gehören also zwei Dinge:BaseCounter

 template <typename T, T .....>

 Der Typname könnte natürlich auch frei gewählt werden
 und für die Pünktchen kann auch ein Name frei gewählt
 werden. Der `range_` als Daten-Menber ist zu löschen
 und det Tp T (aus der Template-Definition) wo immer
 es notwendig ist einzutragen AUCH in spitzen Klammern
 hinter `ICounter`.

 Sowohl im `BaseCounter wie auch im `ChainCounter` wird
 der Range nun nicht mehr als Konstrutor-Argument angegeben
 sondern als Template-Argument, d.h. auch alle VERWENDUNGEN
 dieser beiden müssen in den Tests angepasst werden.
 Für den einstufigen Zähler ist das schon geschehen.
 Für den momentan nicht mitkompilierten dreistufigen
 Tähler und in der Demo-App müsste das noch erfolgen.
*/
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

/*
 WEntsprechende Änderungen wie beim BaseCounter auch
 hier vornehmen ...
*/
class ChainCounter : public BaseCounter {
private:
//  ICounter& next_;
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
