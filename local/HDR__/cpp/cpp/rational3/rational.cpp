#include<cassert>
#include"rational.h"
#include"gcd.h"

// static int gcd(int a, int b)
// {
// 	int re;
// 	while (b != 0){
// 		re = a % b;
// 		a = b;
// 		b = re;	
// 	}	
// 	return a;
// }

std::ostream& operator<<(std::ostream& out, const Rational& rhs){
    return out << rhs.m_num << "/" << rhs.m_den;
}

void Rational::abbreviate()
{
    int g = getGCD(m_num, m_den);
    m_num = m_num / g;
    m_den = m_den / g;

}


Rational::Rational(int num, int den): m_num(num), m_den(den){
    assert(den );
    //int gcd = ::gcd(num, den); // 지역변수와 전역변수 
    //m_den = den/gcd;
    //m_num = num/gcd;
    this->abbreviate();
}


int Rational::getNumber()const{
    return m_num;
}

int Rational::getDenominator()const{
    return m_den;
}

void Rational::setNumber(int num){
    m_num = num;
}

void Rational::setDen(int den){
    assert(den );
    m_den = den;
}

// Rational& Rational::operator=(const Rational& rhs){
//     m_num = rhs.m_num;
//     m_den = rhs.m_den;
//     return *this;
// }
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


