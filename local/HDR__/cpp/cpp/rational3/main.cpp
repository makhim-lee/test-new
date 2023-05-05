//Q = {q/p | pq = I , p!=0}

#include<iostream>
#include"rational.h"

int main()
{
    Rational r1(3, 4); //3/4
    Rational r2(3); //r2 = 3;   //3/1
    Rational r3;       // 0/1
    Rational r4 = r2;

    Rational *p = &r1;
    const Rational *p2 = &r4;

    r3.setNumber(2);
    r3.setDen(5);
    
    r1 = r2 = r3;
    r1 = r3 + r2;  // r1.operator(r3 + r2);  r1.operator=(r3.operator+(r2))

    r1 = r3;
    r1 += r3;
    if(r1 == r3) std::cout << "t/f"<< std::endl;    
    else std::cout<< "f" << std::endl;
    

    std::cout << "r1 : " << r1.getNumber() << "/" << r1.getDenominator() << std::endl;
    std::cout << "r2 : " << r2.getNumber() << "/" << r2.getDenominator() << std::endl;
    std::cout << "r3 : " << r3.getNumber() << "/" << r3.getDenominator() << std::endl;
    std::cout << "r4 : " << r4.getNumber() << "/" << r4.getDenominator() << std::endl;

    // std::cout << r4.getNumber() << r4.getDenominator() << std::endl; --> std::cout << r1 <<std::endl;
    // std::cout << r1; //std::cout.operator<<(r1)x   operator<<(std::cout, r1)o
    std::cout << r1 <<std::endl;

    if(r1 == r3) std::cout << "r1 == r3  " << std::endl;
    else std::cout << "r1 != r3  " << std::endl;
    
    r1++;
    std::cout << r1 <<std::endl;

    String c = r4;
    std::cout << c <<std::endl;

    r4.setNumber(r1.getNumber());

    return 0;
}