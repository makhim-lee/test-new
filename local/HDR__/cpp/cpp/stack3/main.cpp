
#include<iostream>
#include"stack.h"

int main() //<--
{
    Stack s2(100);
    Stack s1;
    //Stack s3 = s2 xx
    //s1 = s2; xx

    s1.push(100);
    s1.push(200);
    s1.push(300);

    std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 2st pop() : " << s1.pop() << std::endl;
    std::cout << "s1 3st pop() : " << s1.pop() << std::endl;

    for(int i = 1; i<= 3; ++i){
        if(!s2.isFull()) s2.push(i);
    }
    
    while (1){
        if(s2.isEmpty())break;
        std::cout<<"s2 pop() : "<<s2.pop()<<std::endl;
    }
    
    //std::cout << s1;
    return 0;
}