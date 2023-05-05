#include<pthread.h>
#include<stdio.h>  
#include<stdlib.h>  // exit
#include<unistd.h>  //sleep

void* thread_main(void* args){
    int param = *((int*)args);
    for (int i = 0; i < param; ++i){
        sleep(1);
        puts("I'm thread\r\n");
    }
    return NULL;
}

int main()
{
    pthread_t pt_id = 0u;
    int thread_param = 10;
    int state = pthread_create(&pt_id/*os줄값*/, NULL, thread_main/*func pointer*/, (void*)&thread_param);

    if(state != 0){
        fputs("Thread error\r\n",stderr);
        exit(1);
    }
    sleep(20); //main threa stop 20s
    return 0;
}

