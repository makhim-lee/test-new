#include<stdio.h>

int main(void)
{
	int score;
	printf("input score : ");
	scanf ("%d", &score);
	
	if (score >= 90){
		printf("score : %d ----pass\n", score);
	}else{
		printf("score : %d ----fail\n", score);
	}
	
	return 0;
}
