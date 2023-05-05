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
	
	int myLott[7];
	
	for (int i = 0; i <= 6; ++i){
		scanf("%d ", &lott[i]);
	}
	int cont = 0;
	
	for (int i = 0; i <= 6; ++i){
		for (int j = 0; j < 6; ++j){
			if (lott[i] == myLott[j]){
				++cont;	
				break;			
			}
		} 
	}
	
	
	for (int i = 0; i <= 6; ++i){
		printf("%d\t", lott[i]);
	}
	printf("\n");
	for (int i = 0; i <= 6; ++i){
		printf("%d\t", myLott[i]);
	}
	
	int rank[] = {7,6,5,4,3,2,1};
	printf("\n%drank", rank[cont]);
	return 0;
}
