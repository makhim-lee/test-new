#include<stdio.h>

void printStringArray1(char (*Arr)[20], int num){
	for (int i = 0;i < num ; ++i){
		printf("%s\n", &Arr[i][0]);  //Arr[i]
	}
}

void printStringArray2(char **Arr, int num){
	for (int i = 0;i < num ; ++i){
		printf("%s\n", Arr[i]);    //&Arr[i][0]
	}
}

int main(void){
	char cites1[][20] = {"asclals", "abcklwkj", "acnslaslk", "asnclasn", "bncw"};
	
	char *cites2[] =  {"asclals", "abcklwkj", "acnslaslk", "asnclasn", "bncw"};
	
	printStringArray1(cites1, 5);
	printStringArray2(cites2, 5);
	
	return 0;
}
