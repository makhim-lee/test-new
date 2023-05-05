#include<stdio.h>
int main(void)
{

	int fahr;
	int celsius;
	int celsius2;
	
	fahr = 100;
	celsius = 5 * (fahr - 32) / 9;
	celsius2 = (5000 * (fahr - 32) / 9-(celsius * 1000) + 5) / 10;
	
	printf("fahr : %d ----> celsius : %d.%d\n",fahr,celsius,celsius2);
	return 0;
}
