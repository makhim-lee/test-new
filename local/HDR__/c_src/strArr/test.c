#include<stdio.h>

int main(void)
{
//	char cites1[5][20] = {"asclals", "abcklwkj", "acnslaslk", "asnclasn", "bncw"};
	
	char *cites2[5] =  {"asclals", "abcklwkj", "acnslaslk", "asnclasn", "bncw"};
	for (int i = 0 ; i < 5; ++i){
		printf("%s\n", cites2[i]);
	}
	return 0;
}	
