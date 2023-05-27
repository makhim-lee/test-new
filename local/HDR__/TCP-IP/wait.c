#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int status = 0;
    pid_t pid = fork(); // 자식생성
    if(pid == 0){ 
        return 3;
    }else {
        printf("Child PID : %d\r\n", pid);
        pid = fork(); // 자식 생성
        if (pid == 0){
            exit(7);
        }else{
            printf("Child PID : %d\r\n",pid);
            wait(&status);
            if(WIFEXITED(status)){ //WIFEXITED()자식의 정상종료확인 매크로
                printf("Chile send one : %d\r\n", WEXITSTATUS(status)); //정상종료를 한경우 자식의 error print
            }
            wait(&status);
            if(WIFEXITED(status)){
                printf("Chile send two : %d\r\n", WEXITSTATUS(status));
            }
            sleep(30);
        }
    }
    return 0;
}