#include<stdio.h>

int main(void)
{
	int score;
	printf("input : ");
	scanf("%d", &score);
	
	if (score >= 90){ //a
		printf("score : %d ----A\n",score);
	} else if (score >= 80 /* && score < 90*/) {  //b
		printf("score : %d ----B\n",score);
	} else if (score >= 70) {  //c
		printf("score : %d ----C\n",score);
	} else if (score >= 60) { //d
		printf("score : %d ----D\n",score);
	} else { //f
		printf("score : %d ----F\n",score);
	}
	
	return 0;
}
