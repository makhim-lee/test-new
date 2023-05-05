#include <stdio.h>
int main(void)
{
	//int code;
	//printf("inPut asc code : ");
	//scanf("%d", &code);
	char ch;
	printf("inPut char : ");
	scanf("%c", &ch);
	
	int isAlpha;
	//isAlpha = code >= 'A' && code <= 'Z';    //65 <= code <= 90 X
	//isAlpha = ch >= 'A' && ch <= 'Z';
	isAlpha = (ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z');
	
	//printf("asc code : %d ----isAlpha :%d\n", code, isAlpha);
	printf("asc code : %c ----isAlpha :%d\n", ch, isAlpha);
	
	return 0;
}
