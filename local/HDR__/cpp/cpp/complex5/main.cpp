#include <ostream>
#include<iostream>
#include"complex.h"
#include "string.h"
3
using std::cout;
using std::endl;

int main(){
    Complex c1;
    Complex c2 = 3.0;    //Complex c2(3.0);
    Complex c3(3.0, 4.0);
    Complex c4 = c3;    //Complexc4(c3);

    c1 = c3;
    c1.real(c4.real());
    c2.imag(c3.imag());

    Complex *p1 = &c1;
    const Complex c5(4.0, 5.0);
    const Complex *ps = &c5;
    //c5 = c1 xxx
    c1.real(c5.real());

    c1 += c2;  // c1 += c2 += c3; daisy chain(x)
    c1 = c2 + c3;

    if (c1 == c2) cout<<"equal"<<endl;
    else cout<<"not equal"<<endl;
    
    ++c1;
    c1++;

    String s = c3;   //(3.0, 4.0i)

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;
    cout << c5 << endl;

    cout << "s : " << s << endl;
    return 0;
}