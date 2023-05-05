#include<stdio.h>
int main(void)
{
	int a, b;
	printf("input a, b :\t");
	scanf("%d %d", &a, &b);
	
	printf("%d > %d : %d\n", a, b, a>b);
	printf("%d < %d : %d\n", a, b, a<b);
	printf("%d >= %d : %d\n", a, b, a>=b);
	printf("%d <= %d : %d\n", a, b, a<=b);
	printf("%d != %d : %d\n", a, b, a!=b);
	
	return 0;
}
