#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>
int sum(int args, ...){
    va_list ap; // ap 아규먼트 point 
    va_start(ap, args); // 각각 포인터를 할당 하겠다
    int val = 0;
    for (int i = 0; i < args; ++i) {
        val += va_arg(ap, int);
    }
    va_end(ap); 
    return val;
}


int main(void){
    int result = sum(5, 1, 2, 3, 4, 5);
    printf("result : %d\n", result);

    result = sum(9, 4, 2, 1, 5, 1, 2, 3, 4, 5);
    printf("result : %d\n", result);

    return 0;
}


//void print_ints(int args, ...)
//{
//    va_list ap;
//    va_start(ap, args);
//    for (int i = 0; i < args; ++i) {
//        int val = va_arg(ap, int);
//        printf("%d: %d\n", i, val);
//    }
//    va_end(ap);
//}
