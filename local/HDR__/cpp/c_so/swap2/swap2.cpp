#include <iostream>
/*
void swap(int& ra, int &rb)
{
	int tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap(double& rx, double& ry)
{
	double tmp = rx;
	rx = ry;
	ry = tmp;
}
*/

template <typename T>
void swap(T& r1, T& r2)
{
	T tmp = r1;
	r1 = r2;
	r2 = tmp;
}

int main()
{
	int a = 100;
	int b = 200;
	swap(a, b);
	std::cout << a << ", " << b << std::endl;
	
	double x = 1.1;
	double y = 2.2;
	swap(x, y);
	std::cout << x << ", " << y << std::endl;
}
