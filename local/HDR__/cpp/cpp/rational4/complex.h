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
    //Complex() {}
    // Complex(const Complex& rhs)  { memberwise copy}
    // ~Complex() 
    // Complex& operator+(const Complex& rhs) {memberwise copy; return this}
    // Complex& operator&() {return this}
    // const Complex& operator&() {return this}

    //Complex(double re);
    Complex(double re = 0.0, double im = 0.0);
    // ~Complex();
    // Complex& operator=(const Complex rhs);
    double real() const;
    double imag() const;
    void real(double re);
    void imag(double im);

    //todo: +=, -=, +=. /=

    //todo: ==,!=,>=,<=
    bool operator==(const Complex& rhs) const; 
    // bool operator!=(const Complex& rhs);

    //todo: +, - , /, *
    const Complex& operator+=(const Complex& rhs);

    const Complex operator+(const Complex& rhs)const;
    
    const Complex& operator++();     //prefix
    const Complex operator++(int ); //postfix

    operator String()const;
};
#endif