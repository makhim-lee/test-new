#include<stdio.h>

int main(void)
{
	char ch;
	printf("input char : ");
	scanf("%c", &ch);
	
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'){  // alphabet
		printf("%c is a alphabet\n", ch);
	}else{  // not alphabet
		printf("%c is not a alphabet\n", ch);
	}
	
	return 0;
}
