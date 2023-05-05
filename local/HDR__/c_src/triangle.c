#include<stdio.h>
int main(void)
{
	//int width;
	//printf("s : ");
	//scanf("%d", &width);
	
	//int height;
	//printf("h : ");
	//scanf("%d", &height);
	
	int width, height;
	//scanf("%d", &width);
	//scanf("%d", &height);
	scanf("%d %d", &width, &height);
	
	double area = width * height / 2.0;
	
	printf("triangle : %.2f\n", area);
	return 0;
}
