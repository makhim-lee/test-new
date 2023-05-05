#include<stdio.h>

int getGCD(int a, int b)
{
	int re;
	while (b != 0){
		re = a % b;
		a = b;
		b = re;	
	}	
	return a;
}
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", getGCD(a, b));
	return 0;
}
