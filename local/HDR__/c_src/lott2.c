#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	srand(time(NULL)); //seed
	
	int lott[7];
	for (int i = 0; i <= 6; ++i){
		lott[i] = rand() % 45 +1;
		for (int j = 0; j < i; ++j){
			if (lott[i] == lott[j]){
				--i;
				break;					
			}
		} 
	}
	
	for (int i = 0; i <= 6; ++i){
		printf("%d\t", lott[i]);
	}
	printf("\n");
	return 0;
}
