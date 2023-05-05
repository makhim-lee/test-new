#include<stdio.h>

int f(void)
{
	return 100;
}

void f2(int *pResult)
{
	*pResult = 100;
}

int main(void)
{
	int re;
	
	re = f();
	printf("re : %d\n", re);
	
	f2(&re);
	printf("re : %d\n", re);
	
	return 0;
}
