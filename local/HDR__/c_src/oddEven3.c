#include<stdio.h>

int main(void)
{
	int num;
	printf("input num : ");
	scanf("%d", &num);
	
//	if (num % 2 /* ==1 */){  // odd
//		printf("%d is a odd num\n", num);
// 	}else{    //even
//		printf("%d is a even num\n", num);
//	}

	printf("%d is a %s num\n", num, (num % 2) ? "odd" : "even");
	
	return 0;
}
