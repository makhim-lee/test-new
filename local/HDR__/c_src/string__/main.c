#include<stdio.h>
#include "string.h"


int main(void)
{
	char str1[] = "hello";  //

	int len = my_strlen(str1);
	printf("len : %d\n", len);

	char str2[6];
	
	my_strcpy(str2, str1);  //string copy
	printf("str2 : %s\n", str2);

	if (my_strcmp(str1, str2) == 0)
		printf("epual\n");
	else
	 	printf("not epual\n");
	
	char str3[] = ", world";
	char str4[15];
	
	my_strcpy(str4, str1);
	printf("str4 : %d\n", str3[7]);
	my_strcat(str4, str3);
	printf("str4 : %s\n", str4);
	
	
	return 0;
}
