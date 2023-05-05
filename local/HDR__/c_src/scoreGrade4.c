#include<stdio.h>

int main(void)
{
	char grades[11] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

	int score;
	printf("input : ");
	scanf("%d", &score);
	
	char grade;
	grade = grades[score/ 10];
	
	printf("score : %d ---- %c\n", score, grade);	
	return 0;
}
