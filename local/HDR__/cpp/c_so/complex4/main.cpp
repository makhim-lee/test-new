#include <iostream>
#include "complex.h"
#include "string.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Complex c1;
	Complex c2 = 3.0;	// Complex c2(3.0);
	Complex c3(3.0, 4.0);
	Complex c4 = c3;	// Complex c4(c3);
	
	c1 = c3;
	c2.real(c3.real());
	c2.imag(c3.imag());
	
	Complex *p1 = &c1;
	const Complex c5(4.0, 5.0);
	const Complex *p2 = &c5;
	
	// c5 = c1; X
	c1.real(c5.real());
	c1.imag(c5.imag());
	
	if (c1 == c2) {
		cout << "c1 and c2 are equal." << endl;
	} else {
		cout << "c1 and c2 are not equal." << endl;
	}
	
	c1 += c2;	// c1 += c2 += c3; daisy chain X
	c1 = c2 + c3;
	
	++c1;
	c1++;
	
	String s = c3;		// (3.0, 4.0i)
	
	cout << "c1 : " << c1 << endl;
	cout << "c2 : " << c2 << endl;
	cout << "c3 : " << c3 << endl;
	cout << "c4 : " << c4 << endl;
	cout << "c5 : " << c5 << endl;
	
	cout << "s = " << s << endl;
	
	cout << "input complex : ";
	Complex c6;
	cin >> c6;
	
	cout << "c6 : " << c6 << endl;
	
	return 0;
}
