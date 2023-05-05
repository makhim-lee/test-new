#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void error_handling (const char*);

void* threadsum(void*);

int sum = 0;
int main()
{
    pthread_t pt_1 = 0ul;
    pthread_t pt_2 = 0ul;
    int range1[] = {1, 5};
    int range2[] = {6, 10};

    if (pthread_create(&pt_1, NULL, threadsum, (void*)range1) != 0){
        error_handling("Create() error");
    }
    
    if (pthread_create(&pt_2, NULL, threadsum, (void*)range1) != 0){
        error_handling("Create() error");
    }
    pthread_join(pt_1, NULL);
    pthread_join(pt_2, NULL);
    fprintf(stdout, "SUMMAITION : %d\r\n", sum);
    return 0;
}

void* threadsum(void*args){
    int start = *((int*)args + 0);  //(int*)args[0]
    int end = *((int*)args + 1);
    while(start <= end){
        sum += start;
        ++start;
    }
    return NULL;
}

void error_handling (const char* _message){
    fputs(_message, stderr);
    fputs("\r\n", stderr);
    exit(1);
}
