#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *pa, int *pb)
{
	 int c = *pa;
	 *pa = *pb;
	 *pb = c;
}
int main(void)
{
	int balls[45];
	// balls[] << ball	
	for (int i = 0; i < 45; ++i){
		balls[i] = i + 1;
	}
	
	
	srand(time(NULL));// surffle
	
	for (int i = 0; i = 100000000; ++i){
		swap(&balls[rand() % 45], &balls[rand() % 45]);
	}
	
	// print index 0~6
	for (int i = 0; i < 7; ++i){
		printf("%d\n", balls[i]);
	}
	
	return 0;
}
