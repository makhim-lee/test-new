#include<iostream>
int main()
{
    std::cout<<"hello" << std::endl;

    //std::cout << "hello"
    operator<<(std::cout, "hello");
    //std::cout.operator<<("hello");

    std::cout << std::endl;
    //operator<<(std::cout, std::endl);  
    std::cout.operator<<(std::endl);

    std::cout<<"hello" << std::endl;
    operator<<(std::cout, "hello").operator<<(std::endl);    //cout.operator

    return 0;
}

#include<iostream>
using std::cout; //cout함수에 namespace 일괄 선언
using std::endl;
int main()
{
    cout<<"hello"<<endl;
    return 0;
}

#include<iosream>
using namespace std; // 모든 namespace 를 std로 선언
int main()
{
    cout<<"hello"<<endl;
    return 0;
}

#include<iosream.h>
int main()
{
    cout<<"hello"<endl;
    return 0;
}


