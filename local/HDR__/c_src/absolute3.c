#include<stdio.h>

int main(void)
{
	int num;
	printf("input num : ");
	scanf("%d", &num);
	
	int result;
	//result = ???;
/*	if (num > 0){
		result = num;
	}else{
		result = -num;
	}
*/		
	result = (num >= 0) ? num : -num;
	
	
	printf("abs value : %d\n", result);
	return 0;
}
