#include<stdio.h>

int main(void)
{
	int a;     //&a == 1000
	int *p;    
	
	a = 100;   
	p = &a;   //p == 1000
	*p = 200;  //a==200
	
	printf("a: %d\n", a);
	
	return 0;
}
