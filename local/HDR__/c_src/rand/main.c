#include<stdio.h>
#include<time.h>
#include"rand.h"

int main(void)
{
/*
	int seed;
	my_srand(%seed, time(NULL));
	
	seed = 0;
	
	int num = rand(&seed);
*/

	my_srand(time(NULL));
	
	for (int i = 0; i <= 10; ++i){
		int num = my_rand();
		
		printf("%d\n", num);
	}
	return 0;
}
