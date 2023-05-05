#include <stdio.h>

long long factorial(int a)
{
	long long fact = 1;
	for (int i = 1; i<=a; ++i){
		fact *= i;
	}
	return fact;
}

int main(void)
{
	for (int i = 1; i <= 100; ++i){
		long long result = factorial(i);
		printf("%d! : %lld\n", i, result);
	}

	return 0;
}
