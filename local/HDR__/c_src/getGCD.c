#include<stdio.h>

int getGCD(int a, int b)
{
	int re = 1;
	int gcd;
	
	while (re != 0){
		if ( a > b ){
			re = a % b;
			gcd = b;
			a = re;
		}else{
			re = b % a;
			gcd = a;
			b = re;
		}
	}
	return gcd;
}

int main(void)
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	printf("%d\n", getGCD(a, b));
	
	return 0;
}
