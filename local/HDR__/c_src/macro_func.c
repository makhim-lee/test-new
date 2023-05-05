#include<stdio.h>

#define SQUARE(a) ((a) * (a))

int square(int i){
    return i * i;
}

int main(void)
{
    int i = 10;
    //int result = square(i);
    int result = SQUARE(i);

    //int result = square(++i); // ((11) * (11))
    //int result = SQUARE(++i); // ((++i) * (++i))  // 11 * 12
    printf("%d\n", result);
    return 0;
}