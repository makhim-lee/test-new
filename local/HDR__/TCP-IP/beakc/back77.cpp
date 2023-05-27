#include<iostream>

int main()
{
    int a1, a2, c, n0;

    std::cin>>a1>>a2>>c>>n0;
   
    std::cout<<((a1 * n0 + a2) <= (c * n0))<<std::endl;

    return 0;
}