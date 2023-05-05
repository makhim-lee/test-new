#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include "string.h"
#include "gcd.h"

class Rational {
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	int num_;
	int den_;
	
	void abbreviate();	// helper func.
	
public:

	Rational(int num = 0, int den = 1);
	Rational(const Rational& rhs);
//	~Rational();
	
	Rational& operator=(const Rational& rhs);
	// +=, -=, *=, /=
	// &=, |= X
	
	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	// !=, >, <, >=, <=
	
	const Rational operator+(const Rational& rhs) const;
	const Rational operator-(const Rational& rhs) const;
	const Rational operator*(const Rational& rhs) const;
	const Rational operator/(const Rational& rhs) const;
	// % X
	// ++, -- X
	const Rational& operator+=(const Rational& rhs);
	
	const Rational& operator++();
	const Rational operator++(int );
	
	operator String() const;

	int getNum() const;
	int getDen() const;
	
	void setNum(int num);
	void setDen(int den);
};

#endif
