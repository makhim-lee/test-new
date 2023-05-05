#include<stdio.h>

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	int nums2[] = {1, 2, 3, 4, 5};
	
/*	if (nums==nums2) // &nums[0] == &nums2[0]
		printf("equal\n");
	else
		printf("not equal\n"); */
	
	int i;
	for (i = 0; i < 5; ++i)
		if (nums[i] != nums2[i])
			break;
			
	
	if (i == 5) 
		printf("equal\n");
	else
		printf("not equal\n");
	
	
	return 0;
}
