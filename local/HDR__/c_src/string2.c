#include<stdio.h>
#include<string.h>

//typedef unsigned long size_t;

int main(void)
{
	char str1[] = "hello";  //

	int len = strlen(str1);
	printf("len : %d\n", len);

	char str2[6];
//	char str2;   x
//	cahr str2[5]; x
//	char str2[10];  O

	strcpy(str2, str1);  //string copy
	printf("str2 : %s\n", str2);

	if (strcmp(str1, str2) == 0)
		printf("epual");
	else
	 	printf("not epual");
	
	char str3[] = ", world";
	char str4[15]; //char str4[10]  ...X
	strcpy(str4, str1);
	strcat(str4, str3);
	printf("str4 : %s\n", str4);
	
	
	return 0;
}
