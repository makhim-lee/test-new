#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//signal (정수 ㅡ함수 );
// os 이벤트가 발생하면 함수 호출

void timeout(int _signal){
    if(_signal == SIGALRM){ //14
        puts("time out");
    }
    alarm(2);
}

void keycontrol(int _signal){
    if(_signal == SIGINT){
        puts("Ctrl + c pressed\r\n");
    }
}

int main()
{
    signal(SIGALRM, timeout); //alarm 만료시
    signal(SIGINT, keycontrol); //ctrl c 눌렀을시
    alarm(2);
    for(int i = 0; i < 3; ++i){
        puts("wait... \r\n");
        sleep(100);
    }
    return 0;
}