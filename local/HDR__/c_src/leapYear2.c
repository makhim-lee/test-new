#include<stdio.h>

int main(void)
{
	int year;
	printf("input year : ");
	scanf("%d", &year);
	
	//short-cut circuit if (year % 400 == 0 || year % 100 != 0 &&  year % 4 == 0)
	
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
		printf("%d is a leap year\n", year);
	} else{
		printf("%d is a ordinary year\n", year);
	}
	 
	return 0;
}
