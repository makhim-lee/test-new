#include<stdio.h>
int main(void)
{

	int num = 100;
	int nums[10] = {50, 42, 62, 63, 86, 74, 88, 23, 14, 66};
	
	int sum = 0;
	for (int i = 0; i < 10; ++i){
		sum += nums[i];  // sum = sum + sum
	}
	
	printf("sym : %d\n", sum);
	
/*	int sum = 0;
	for (int i = 0; i < 10; ++i){
		if (nums[i] <= 50){
			sum += nums[i];
		}
	}*/
	
	return 0;
}
