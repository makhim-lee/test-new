#include<stdio.h>
int main(void)
{

	int nums[10] = {50, 42, 62, 63, 86, 74, 88, 23, 14, 66};

	//sorting
	for (int i = 0 ; i < 10 - 1; ++i){
		for (int j = i + 1; j < 10 ; ++j){
			if (nums[i] > nums[j]){
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}

	for (int i = 0 ; i < 10; ++i){
		printf("%d\t", nums[i]);
	}
	printf("\n");	
		
	return 0;
}
