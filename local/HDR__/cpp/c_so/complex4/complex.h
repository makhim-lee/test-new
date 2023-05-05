#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include "string.h"

class Complex {
friend std::istream& operator>>(std::istream& in, Complex& rhs);
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);

private:
	double re_;
	double im_;
	
public:
	// Complex& operator() { return this; }
	// const Complex& operator&() const { return this; }
	
	Complex(double re = 0.0, double im = 0.0);
	// Complex(const Complex& rhs) { /* memberwise copy */ }
	// ~Complex() {}
	
	// Complex& operator=(const Complex& rhs) { /* memberwise copy */ return *this; }
	const Complex& operator+=(const Complex& rhs);
	// +=, -=, *=, /= is not implemented.
	
	bool operator==(const Complex& rhs) const;
	// !=, >, <, >=, <= is not implemented
	
	const Complex operator+(const Complex& rhs) const;
	// -, *, / is not implemented.
	
	const Complex& operator++();		// prefix
	const Complex operator++(int );	// postfix
	
	operator String() const;
	
	double real() const;
	double imag() const;
	
	void real(double re);
	void imag(double im);
	
};

#endif
