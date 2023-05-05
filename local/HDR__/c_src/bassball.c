#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
	int question[3];

	srand(time(NULL)); //seed
	for (int i = 0; i < 3; ++i){  // question[i]<-- computer, random number[1, 9] .unique
		int num = rand() %9 +1;
		question[i] = num;
	
		for(int j = 0; j < i ; (question[i] == question[j])? --i : ++j){
		}
	}
//	printf("%d %d %d\n", question[0], question[1], question[2]);
	
	
	int strike, ball;
	strike = 0;
	ball = 0;
	
	int count = 0;
	while ( strike != 3){
		
		int answer[3];
		printf("input answer : ");
		scanf("%d %d %d", &answer[0], &answer[1], &answer[2]);
		
		strike = ball = 0;
		
		for(int i = 0; i < 3; ++i){  //condt strike ball
			for(int j = 0; j < 3; ++j){
				if(question[i] == answer[j]){
					(i == j) ? ++strike : ++ball;
				}
			}
		}
		printf("%d strike %d ball\n", strike, ball);
		
		++count;	
	}
	
	printf("count : %d\n", count);
	
	return 0;
}
