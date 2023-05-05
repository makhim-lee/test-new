#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
    double re;  //real num
    double im;  //image num
public:
    Complex();                      //function overloading
    Complex(double re);             //one-interface multi-method
    Complex(double re, double im);  
    ~Complex();
    
    double real();
    double imag();

    void real(double re);
    void imag(double im);

};


#endif