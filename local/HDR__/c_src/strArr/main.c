#include"strArr.h"
#include<stdio.h>


int main(void){
	char cites1[][20] = {"asclals", "abcklwkj", "acnslaslk", "asnclasn", "bncw"};
	
	char *cites2[] =  {"asclals", "abcklwkj", "acnslaslk", "asnclasn", "bncw"};
	
	printStringArray1(cites1, 5);
	printStringArray2(cites2, 5);
	
	return 0;
}
