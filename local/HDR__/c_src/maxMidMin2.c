#include<stdio.h>
int main(void){
	int a, b, c;
	printf("input num a,b,c :");
	scanf("%d %d %d", &a, &b, &c);
	
	int max, mid, min;
	
	
	if (a >b) {
		if (c >a){
			max = a;
			min = b;
		}else{
			mid = b;
			min = a;
		}
		
	if (c > max) {
		if (c >a){
			min = max;
			mix = c;
		}else if(c > min){
			mid = c;
		}else{
			mid = min;
			min = c;
		}
	
	printf("min : %d mid : %d max : %d\n", min, mid, max);
	return 0;
}


