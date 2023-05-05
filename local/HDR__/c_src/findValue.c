#include<stdio.h>
int main(void)
{

	int nums[10] = {50, 42, 62, 63, 86, 74, 88, 23, 14, 66};
	
	int value;
	printf("input value : ");
	scanf("%d", &value);
	
	int i; // save value i
	for (i = 0; i < 10; ++i)
		if (nums[i] == value) break;
	
	if(i<10) 
		printf("%d is found index : %d\n", value, i);
	else 
		printf("%d is not found\n", value);
	
	
	return 0;
}
