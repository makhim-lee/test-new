//Q = {q/p | pq = I , p!=0}

#include<iostream>
#include"rational.h"

int main()
{
    Rational r1(3, 4); //3/4
    Rational r2(3);    //3/1
    Rational r3;       // 0/1


   r3.setNumber(3);
   r3.setDen(4);

    std::cout << "r1 : " << r1.getNumber() << "/" << r1.getDenominator() << std::endl;
    std::cout << "r1 : " << r2.getNumber() << "/" << r2.getDenominator() << std::endl;
    std::cout << "r1 : " << r3.getNumber() << "/" << r3.getDenominator() << std::endl;

    return 0;
}