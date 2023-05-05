#include<stdio.h>
#include"power.h"


int main(void)
{
	for (int i = 0; i <= 32; ++i) {
		long long result = power(2, i);
		printf("*2 power of %d : %lld\n", i, result);
	}
	return 0;
}

