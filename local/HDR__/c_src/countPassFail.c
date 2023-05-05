#include<stdio.h>

int main(void)
{
	int scores[5];
	for (int i = 0; i < 5; ++i){
		scanf("%d", &scores[i]);
	}
	
	int pass = 0;
	int fail = 0;
	
	for (int i = 0; i < 5; ++i){
		if (scores[i] >=60){//pass
			++pass;
		}else{ //fail
			++fail;
		}
	}
	printf("pass : %d fail : %d\n", pass, fail);
	return 0;
}
