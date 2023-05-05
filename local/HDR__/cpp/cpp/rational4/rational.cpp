#include<cassert>
#include<iostream>
#include"rational.h"
#include"gcd.h"
#include"complex.h"

#ifndef INLINE
#define inline
#include"rational.inl"
#endif


std::ostream& operator<<(std::ostream& out, const Rational& rhs){
    return out << rhs.m_num << "/" << rhs.m_den;
}

std::istream& operator>>(std::istream& istr, Rational& r) {
    long num = 0, den = 1;
    istr >> num;
    if ( istr.peek() == '/' ) {  // 버퍼 내용 확인 
        istr.ignore(1);           // peek된 내용 무시
        istr >> den;              // 분모 꺼내기
    }
    if ( istr ) r = Rational(num,den);
    return istr;
}

// std::istream& operator>>(std::istream& istr, Complex& rhs) {
//     double re = 0.0, im = 0.0;
//     char c = 0;
//     istr >> c;
//     if (c == '(') {
//         istr >> re >> c;
//         if (c == ',') istr >> im >> c;
//         if (c == 'i') istr >> c;
//         if (c != ')') istr.clear(ios::failbit); // set state
//     } else {
//         istr.putback(c);
//         istr >> re;
//     }
//     if (istr) rhs = Complex(re, im);
//     return istr;
// }



void Rational::abbreviate()
{
    int g = getGCD(m_num, m_den);
    m_num = m_num / g;
    m_den = m_den / g;

}


Rational::Rational(int num, int den): m_num(num), m_den(den){
    assert(den );

    this->abbreviate();
}




bool Rational::operator==(const Rational& rhs) const{
    return(m_num == rhs.m_num && m_den == rhs.m_den);
}
bool Rational::operator!=(const Rational& rhs) const{
    return !this->operator==(rhs);   //return !((*this)->operator==(rhs));   !(*this)operator==(rhs) 
}

const Rational& Rational::operator+=(const Rational& rhs){
    this->operator+(rhs);
    return *this;
}

const Rational Rational::operator+(const Rational& rhs) const{
    int num = m_num * rhs.m_den + rhs.m_num * m_den;
    int den = m_den * rhs.m_den;
    return Rational(num, den); 
}
const Rational Rational::operator-(const Rational& rhs) const{
    Rational result(m_num * rhs.m_den - rhs.m_num * m_den, m_den * rhs.m_den);
    return result; 
}
const Rational Rational::operator*(const Rational& rhs) const{
    int num = m_num * rhs.m_num;
    int den = m_den * rhs.m_den;
    return Rational(num, den); 
}
const Rational Rational::operator/(const Rational& rhs) const{
    int num = m_num * rhs.m_den;
    int den = m_den * rhs.m_num;
    return Rational(num, den); 
}

Rational& Rational::operator++(){
    m_num += m_den; // c1.operator++(1*c1.den);
    return *this;
}
const Rational Rational::operator++(int ){
    Rational tmp(*this);
    m_num += m_den;
    return tmp;
}

Rational::operator String() const{
    char buf[128];
    sprintf(buf, "(%d/%d)", m_num, m_den);
    String result(buf);
    return result;
}

