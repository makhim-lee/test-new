#include<stdio.h>

int sumMatrix(int (*matrix)[4], int row, int col)
{
	int sum = 0;
	
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			sum += matrix[i][j];
		}
	}
	return sum;
}

int main(void)
{
	int matrix[][4] = {
		{1, 2, 3, 4}, 
		{5, 6, 7, 8}, 
		{9, 10, 11, 12}
	};
	
	int sum = sumMatrix(matrix, 3, 4);
	
	printf("sum : %d\n", sum);
	return 0;
}
