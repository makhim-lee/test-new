#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
// cout << c1; // cout

// class Complex; // class선언
// std::ostream& operator<<(std::ostream& out, const Complex& rhs);

class Complex{
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);

private:
    double re;
    double im;
public:
    Complex(double re = 0.0, double im = 0.0);
    Complex(const Complex& rhs);
    // ~Complex()  비어 있으면 없어도됨 컴파일러가 해줌
    // ~Complex();
    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs);
    bool operator!=(const Complex& rhs);

    Complex operator+(const Complex& rhs);
    const Complex operator-(const Complex& rhs);

    double real();
    double imag();

    void real(double re);
    void imag(double im);

    

};



#endif