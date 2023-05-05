#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv){
    if(argc != 3){
        fprintf(stderr, "[usage] ./add 1 2\n");
        exit(1);
    }

    int left = atoi(argv[1]);
    int right = atoi(argv[2]);

    printf("%d\n", left + right);
    return 0;
}