#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void timeout(int _signal){
    if(_signal == SIGALRM){
        puts("Time out \r\n");
    }
    alarm(2);
}

int main(int argc, char *argv[])
{
    struct sigaction act;
    act.sa_handler = timeout;
    sigempyset(&act.sa_mask);// reset sa_mask 
    act.sa_flags = 0; //reset 0
    sigaction(SIGALRM, &act, 0); //구조체 변수 전달
    alarm(2);

    for (int i = 0; i < 3; ++i){
        put("wait ...\r\n");
        sleep(100);
    }
    return 0;
    
}