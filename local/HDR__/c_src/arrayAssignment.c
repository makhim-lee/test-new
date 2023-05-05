#include<stdio.h>

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	int nums2[5];
	
	//nums2 = nums;
	
	for (int i = 0; i < 5; ++i){
		nums2[i] = nums[i];
	}
	
	for (int i = 0; i < 5; ++i){
		printf("%d\n", nums2[i]);
	}
	return 0;
}
