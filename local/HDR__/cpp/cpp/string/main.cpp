#include<iostream>
#include"string.h"

int main()
{
    String s1;
    String s2 = "just the way you are"; // String s2("just the way you are")
    String s3 = s2;                     // String s3(s2);

    s1 = s2 = s3;
    if(s1 == s2) std::cout << "equal" << std::endl;
    else std::cout << "not equal" << std::endl;


    String s4 = " - billy joel";
    s1 = s2 + s4;

    s4 = "wonderful tonight";  //String tmp(""); s4.operator=(tmp); tmp,~String();

    //std::cout << "s1 : " << s1.c_str() <<std::endl;
    std::cout << "s1 : " << s1 <<std::endl;
    std::cout << "s2 : " << s2 <<std::endl;
    std::cout << "s3 : " << s3 <<std::endl;
    std::cout << "s4 : " << s4 <<std::endl;

    std::cout << "s1 len : " << s1.size() <<std::endl;
    return 0;
}