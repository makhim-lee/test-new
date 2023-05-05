#include<stdio.h>

int main(void)
{
	char name[];
	scanf("%s", name); // scanf("%s", &name[0]);//fgetf 한줄 통째로 스캔 
	
	printf("%s", name); //printf("%s", &name[0]);
	return 0;
}
