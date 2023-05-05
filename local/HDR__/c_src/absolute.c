#include<stdio.h>

int main(void)
{
	int num;
	printf("input num : ");
	scanf("%d", &num);
	
	if (num < 0){
		num = -num;
	}/* else{
		num = num;
	}*/
	
	printf("abs value : %d\n", num);
	return 0;
}
