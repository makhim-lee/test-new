#include<iostream>

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void swap3(int &ra, int &rb)
{
    int tmp = ra;
    ra = rb;
    rb = tmp;
}

int main()
{
    int a, b;

    a = 100;
    b = 200;

    std::cout << "a: " << a << "\t" <<"b : " << b <<std::endl;
    swap(a, b);
    std::cout << "a: " << a << "\t" <<"b : " << b <<std::endl;

    std::cout << "a: " << a << "\t" <<"b : " << b <<std::endl;
    swap2(&a, &b);
    std::cout << "a: " << a << "\t" <<"b : " << b <<std::endl;

    std::cout << "a: " << a << "\t" <<"b : " << b <<std::endl;
    swap3(a, b);
    std::cout << "a: " << a << "\t" <<"b : " << b <<std::endl;

    return 0;
}