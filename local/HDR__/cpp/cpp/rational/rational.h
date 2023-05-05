#ifndef RATIONAL_H
#define RATIONAL_H

class Rational{
private:
    int num;
    int den; //denominator
public:
    Rational(int num, int den);
    Rational(int num);
    Rational();
    ~Rational();

    int getNumber();
    int getDenominator();

    void setNumber(int num);
    void setDen(int den);
};

#endif