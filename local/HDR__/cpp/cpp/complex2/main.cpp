#include<iostream>
#include"complex.h"
int main()
{
    Complex c1(3.0, 4.0); // 3.0, 4.0i
    //Complex c2(3.0);     //3.0+0.0i
    Complex c2 = 3.0;
    Complex c3;         // 0, 0i

    Complex c4 = c1;


    c3.real(c1.real());
    c3.imag(c2.imag());
//    c3 = c1;  // c3.operator=(c1) or operator=(c3, c1)
//    c3 = &c1;   //c3.operator=(&c1);   모양이 직관적이지 않아서 연산자중복에선 포인터를 사용x
    c3 = c1;   //레퍼런스를 사용하면 모양을 유지하면서 값을 바꿀수 있음

    //c1.operator==(c3) or operator==(c1,c3)
    if(c1 == c3) std::cout << "c1 and c3 are equal" << std::endl;
    else std::cout << "c1 and c3 are not equal" << std::endl;

    std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" <<std::endl;
    std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" <<std::endl;
    std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" <<std::endl;
    return 0;
}