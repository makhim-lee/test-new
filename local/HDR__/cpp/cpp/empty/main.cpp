#include<iostream>
#include "empty.h"


int main()
{
    Empty e1;
    Empty e2 = e1; // Empty e2(e1);

    e1 = e2;

    Empty *p = &e1; // e1.operator$()   // 일반 객체에 대해 주소값 구함 
    std::cout<<p<<std::endl;
    const Empty e3 = e1; 
    const Empty *p2 = &e3; //const e3.operator&(); const Empty *operator&()// 상수객체에 대해 주소값 구함
    return 0;
}

