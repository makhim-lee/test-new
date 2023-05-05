#ifndef COMPLEX_H
#define COMPLEX_H
#include "String.h"
//using std ostream xxxx
class Complex{

friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);

private:
    double m_re;
    double m_im;
public:
    
    Complex(double re = 0.0, double im = 0.0);

    double real() const;
    double imag() const;
    void real(double re);
    void imag(double im);

    bool operator==(const Complex& rhs) const; 

    const Complex& operator+=(const Complex& rhs);

    const Complex operator+(const Complex& rhs)const;
    
    const Complex& operator++();     //prefix
    const Complex operator++(int ); //postfix

    operator String()const;
};
#define INLINE
#ifdef INLINE
#include "complex.inl"
#endif
#endif