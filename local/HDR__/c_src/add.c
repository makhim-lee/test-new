#include<stdio.h>
#include <stdlib.h>

//int main (void)
int main(int argc, char **argv)
{
	for (int i = 0; i < argc; ++i){
		printf("%s\n", argv[i]);
	}	
	
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	printf("%d\n", a + b);
	return 0;
}

//  ./add 100 200 <-- argc/3 
