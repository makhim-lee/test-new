#include<stdio.h>

int findMax(const int *pArr,int size)
{
	int max pArr[0];
	for(int i = 0;i < size; ++i){
		if (pArr[i] > max) max = pArr[i]; 
	}
	return max;
}



int main(void)
{	
	int nums[10] = {50, 30, 100, 20, 44, 64, 78, 23, 52, 88};
	
	int max = findMax(nums, 10);
	
	printf("max : %d\n", max);
	return 0;
}
