#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
#include<cassert>
#include"String.h"
#include"complex.h"

class Rational{
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);
friend std::istream& operator>>(std::istream& istr, Complex& rhs);
friend std::istream& operator>>(std::istream& istr, Rational& r);

private:
    int m_num;
    int m_den; //denominac

    void abbreviate(); // helper func.
public:
    //void abbreviate();// int gcd(int, int);

    Rational(int num = 0, int den = 1);
    //Rational (const Rational& rhs); = {memberwise}
    //~Rational();

    int getNumber()const;
    int getDenominator()const;
    void setNumber(int num);
    void setDen(int den);

    //Rational& operator=(const Rational& rhs); ={memberwise copy}

    const Rational& operator+=(const Rational& rhs);
    Rational& operator++();
    const Rational operator++(int );

    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;

    const Rational operator+(const Rational& rhs) const;
    const Rational operator-(const Rational& rhs) const;
    const Rational operator*(const Rational& rhs) const;
    const Rational operator/(const Rational& rhs) const;

    operator String()const;

    
};


#ifdef INLINE
#include "rational.inl"
#endif

#endif