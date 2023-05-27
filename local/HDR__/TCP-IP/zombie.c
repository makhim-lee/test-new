#include<stdio.h>
#include<unistd.h>   //fork()

int main()
{
    __pid_t pid =fork();
    if(pid == 0){ // 자식 프로세스
        puts("chlid\r\n");
    }else { // 부모 프로세스
        printf("chlid PID : %d\r\n", pid);
        sleep(30); 
    }
    if(pid == 0) puts("END child\r\n");
    else puts("END parent\r\n");

    
    return 0;
}