#include <ostream>
#include <cstdio>
#include "string.h"
#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs){
    //return out << "(" << rhs.real() << "," << rhs.imag()<<"i)";
    return out << "(" << rhs.m_re <<"+"<< rhs.m_im<< "i)";
}

Complex::Complex(double re, double im) :m_re(re), m_im(im)  //constructor init. list
{
    ///*this->*/m_re = re;
    //m_im = im;
    
}

Complex::operator String() const {
    char buf[128];
    sprintf(buf, "(%f, %fi)", m_re, m_im);

    String result(buf);
    return result;
}

double Complex::real()const{
    return m_re;
}
double Complex::imag()const{
    return m_im;
}

void Complex::real(double re){
    m_re = re;
}
void Complex::imag(double im){
    m_im = im;
}

bool Complex::operator==(const Complex& rhs)const{
    return m_re == rhs.m_re && m_im == rhs.m_im;
}

// bool Complex::operator!=(const Complex& rhs){
//     return !this->operator==(rhs);
// }

const Complex& Complex::operator+=(const Complex& rhs){
    m_re += rhs.m_re;
    m_im += rhs.m_im;

    return *this;
}

const Complex Complex::operator+(const Complex& rhs)const{
    Complex result(m_re + rhs.m_re, m_im + rhs.m_im);
    return result;
}

const Complex& Complex::operator++(){
    m_re += 1.0;
    return *this;
}

const Complex Complex::operator++(int){
    Complex tmp(*this);
    m_re += 1.0;
    return tmp;
}