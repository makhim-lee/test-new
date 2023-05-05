#include<stdio.h>
int main(void)
{
	int M , W;
	printf("input #man #woman : \t");
	scanf("%d %d", &M, &W);
	
	int sum = M + W;
	
	//double manRatio = M * 100.00 / sum;
	//double womanRatio =W * 100.00 / sum;
	
	//double manRatio = 1.0 * M / sum * 100;
	//double womanRatio = 1.0 * W / sum * 100;

	double manRatio = (double)M / sum * 100;
	double womanRatio = (double)W / sum * 100;
	
	printf("manratio : %.2f%% womanratio : %.2f%%\n", manRatio , womanRatio);
	return 0;
}
