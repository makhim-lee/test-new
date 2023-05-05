
#include<iostream>
#include"stack.h"


int main() //<--
{
    Stack<int> s1;    
    s1.push(100);
    s1.push(200);
    s1.push(300);

    while(!s1.isEmpty()) std::cout<<s1.pop()<<std::endl;

    Stack(Complex) s2;
    s2.push(Complex(3.0));
    s2.push(Complex(3.0, 4.0));
    s2.push(Complex());

    while(!s2.isEmpty()){
        std::cout<<s2.pop()<<std::endl;
    }
    return 0;
}