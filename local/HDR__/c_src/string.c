#include<stdio.h>

int main(void)
{
	//char str[] = {'h','e','\0'}; //null char
	char str[6] = "hello";
	
	printf("str: %s\n", str);
	printf("str+2: %s\n", str + 2);
	
	char str2[6];
	
	int i;
	for (i = 0; str[i] != '\0'; ++i){
		str2[i] = str[i];
	}
	str2[i] = '\0';
	printf("str2 ; %s\n", str2);
	
	return 0;
}
