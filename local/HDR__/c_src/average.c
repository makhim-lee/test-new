#include <stdio.h>
int main(void)
{
	int math, eng, kor;
	
	printf("math, eng, kor\n");
	scanf("%d %d %d", &math, &eng, &kor);
	
	int sum = math + eng + kor;
	double avg = (double)sum / 3.0;

	printf("avg : %.2f\t sum : %d\n", avg, sum);
	return 0;
}
