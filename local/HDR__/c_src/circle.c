#include<stdio.h>
#define PI 3.14

int main(void)
{
	//int rad;
	double rad;
	printf("input rad : ");
	//scanf("%d", &rad);
	scanf("%lf", &rad);
	
	double area = rad * rad * PI;
	
	printf("circle : %.2f\n", area);
	return 0;
}
