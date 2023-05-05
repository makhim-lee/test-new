#include<stdio.h>

typedef struct /*student*/{
	char name[21];
	int kor;
	int eng;
	int mat;
	int sum;
	double ave;
	int rank;
} Student;

int main(void)
{
	Student book = {};
	printf("%d", book.kor);
	return 0;
}
