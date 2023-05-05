#include<stdio.h>
int main(void)
{

	int nums[10] = {50, 42, 62, 63, 86, 74, 88, 23, 14, 66};

	for (int i = 9 ; i >= 1; --i){
		for (int j = 0 ; j < i; ++j){
			if (nums[j] > nums[j+1]){
				int tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}


	for (int i = 0 ; i < 10; ++i){
		printf("%d\t", nums[i]);
	}
	printf("\n");	
		
	return 0;
}
