#include<stdio.h>
int main(void){
	int a, b, c, d;
	printf("input num a,b,c :");
	scanf("%d %d %d", &a, &b, &c);
	
/*
	if (a > b && a > c){//a = max
		printf("max : %d mid : %d min : %d\n", a, (b > c) ? b : c, (b > c) ? c : b);
	} else if(b > c){ //b = max
		printf("max : %d mid : %d min : %d\n", b, (a > c) ? a : c, (a > c) ? c : a);
	} else { //c = max
 		printf("max : %d mid : %d min : %d\n", c, (b > a) ? b : a, (b > a) ? a : b);
	} 
*/

/*	if (a > b){
		//swap(&a, &b);
		d = a;
		a = b;
		b = d;
	}
	if (b > c){
		//swap(&b, &c);
		d = b;
		b = c;
		c = d;
	}
	if (a > b){
		//swap(&a, &b);
		d = a;
		a = b;
		b = d;
	}
	printf("min : %d mid : %d max : %d\n", a, b, c);
*/

	if (a >b) {
		if (c >a){
			printf("min : %d mid : %d max : %d\n", c, a, b);
		}else if (c < b){
			printf("min : %d mid : %d max : %d\n", a, c, b);
		}else{
			printf("min : %d mid : %d max : %d\n", a, b, c);
		}
	}else {
		if (c > b){
			printf("min : %d mid : %d max : %d\n", c, b, a);
		}else if(c > a){
			printf("min : %d mid : %d max : %d\n", b, c, a);
		}else{
			printf("min : %d mid : %d max : %d\n", b, a, c);
		}

	return 0;
}


