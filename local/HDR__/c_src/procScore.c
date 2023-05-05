#include<stdio.h>

int main(void)
{
	
	//int score, score1...
	//scanf("%d", &score).....
	//int sum = score + score1 + score2....
	
	int score[50];
	
	for(int i = 0; i < 50; ++i){
		scanf("%d", &score[i]);
	}
	
	int sum;
	for(int i = 0; i < 50; ++i){
		sum = sum + score[i];
	}
	
	double ave = (double)sum / 50.0;
	printf("sum : %d \tscore ave : %.2f\n", sum, ave);
	return 0;
}
