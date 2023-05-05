#include"strArr.h"
#include <stdio.h>

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

