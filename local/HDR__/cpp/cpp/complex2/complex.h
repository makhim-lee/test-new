#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
    double re;  //real num
    double im;  //image num
public:
    //Complex();                      //default constructor
    //Complex(double re);             //convert. const.
    Complex(double re = 0.0, double im = 0.0);  //ordinary const. // default argument
    Complex(const Complex &rc);       //copy const.
    //Complex(const Complex c);  <-- infinitly copy const is call!!
    ~Complex();                     // destructor

    double real();
    double imag();
    void real(double re);
    void imag(double im);

    //void operator=(Complex c);
    //void operator=(const Complex *pc);
    void operator=(const Complex &rc);
    bool operator==(const Complex &rc);
};


#endif