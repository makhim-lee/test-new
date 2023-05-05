#include<stdio.h>
#include<stdlib.h>

int compare(const void *one,const void *two){
	if(*(int *)one>*(int *)two)
		return 1;
	else if(*(int *)one<*(int*)two)
		return -1;
	else return 0;
}
int median(const int *pArr, int size){
    int numsCopy[size];

    for (int i = 0; i < size; ++i)
    {
        numsCopy[i] = pArr[i];
    }
    
    qsort(&numsCopy, size, sizeof(int), compare);
    int result = (size %2)? numsCopy[size/2]:(numsCopy[(size-1)/2] + numsCopy[size/2])/2; 
    
    return result;
}


int main(void)
{
    int nums[] = {30, 20, 40, 60, 90, 10, 50, 70, 100, 80};

    int result = median(nums, 10);
    printf("median : %d\n", result); 
    return 0;
}