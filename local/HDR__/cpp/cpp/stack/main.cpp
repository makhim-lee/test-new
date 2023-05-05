//#include<cstdio>
#include<iostream>
#include"stack.h"

int main() //<--
{
    Stack s1(100), s2(10);
    // s1.initStack(100);
    // s2.initStack(10);

    s1.push(100);
    s1.push(200);
    s1.push(300);

    // printf("%d\n", s1.pop());
    // printf("%d\n", s1.pop());
    // printf("%d\n", s1.pop());

    // std::cout << "s1 1st pop() : ";
    // std::cout << s1.pop();
    // std::cout << std::endl;

    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3st pop() : " << s1.pop() << std::endl;

    s2.push(600);
    s2.push(500);
    s2.push(400);

    // printf("%d\n", s2.pop());
    // printf("%d\n", s2.pop());
    // printf("%d\n", s2.pop());
    
    std::cout << "s2 3st pop() : " << s2.pop() << std::endl;
    std::cout << "s2 1st pop() : " << s2.pop() << std::endl;
    std::cout << "s2 2st pop() : " << s2.pop() << std::endl;

    // s1.cleanupStack();
    // s2.cleanupStack();
    return 0;
}