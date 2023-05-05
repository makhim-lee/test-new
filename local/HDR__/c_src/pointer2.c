#include<stdio.h>
int main(void)
{
	int num;
	int nums[5];
	
	int *p = NULL;
	
	p = &num;
	p = &nums[1];
	
	*p = 100;

	return 0;
}

