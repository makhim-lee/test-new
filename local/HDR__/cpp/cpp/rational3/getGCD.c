#include<stdio.h>
#include"gcd.h"

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

