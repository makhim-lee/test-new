#include<stdio.h>
int main(void)
{
	int sum = 0;
	
	int i = 1;
	while(i <= 10){
		sum = sum + i;
		++i;   ///i = i +1;
	} 
	
	printf("sum {1,10] : %d\n", sum);
	return 0;
}
