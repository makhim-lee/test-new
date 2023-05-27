#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>  // true, false
#include<sys/socket.h>
#include<arpa/inet.h>
#include<signal.h>  //siganl()
#include<sys/wait.h>  //wait()

void error_handling(const char*);
void read_childpro(int);

int main(int argc, const char* argv[])
{
    pid_t pid; // save child process id
    int serv_sock = 0;
    int clnt_sock = 0;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    struct sigaction act; // control siganl to unsing strcut  
    socklen_t addr_size;
    int str_length = 0;
    bool state = false;
    char buf[BUFSIZ] = {'\0',};

    if (argc != 2)error_handling("ECHO_MULTI_SERVER 127.0.0.1 9999");

    act.sa_handler = read_childpro; // reg func
    sigemptyset(&act.sa_mask); // reset sa_mask
    act.sa_flags = 0; //set 0
    state = sigaction(SIGCHLD, &act, 0); //end chaild 호출
    if(state == -1) error_handling("sigaction() error"); 
// TODO socket()
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)error_handling("socket() error");
    memset(&serv_addr, 0, sizeof serv_addr);
    memset(&clnt_addr, 0, sizeof clnt_addr);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
// TODO bind
    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof serv_addr) == -1) error_handling("bind() error");
// TODO listen
    if(listen(serv_sock, 5) == -1 ) error_handling("listen() error");
// TODO accept
    while (true)
    {
        addr_size = sizeof clnt_addr;
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, (socklen_t*)&addr_size);
        if(clnt_sock == -1) continue; // wait next client
        else puts("New clinet connected ..\r\n");
//TODO 클론생성
        pid = fork(); // 자식생성
        if(pid == -1){
            close(clnt_sock);
            continue;
//TODO 자식프로세스 동작코드
        }else if(pid == 0){  
            close(serv_sock); //복사되어서serv_sock두개가 생겨서 하나를 close
            while ((str_length = read(clnt_sock, buf, BUFSIZ)) != 0)
            {
                write(clnt_sock, buf, str_length); // sned to client
            }
            close(clnt_sock);
            puts("Clinet disconnectde ....");
            return 0;
        }else close(clnt_sock); //부모프로세스에서 종료시킴
    }
    close(serv_sock);
    return 0;
}

void error_handling(const char* _message){
    fputs(_message, stdout);
    fputs("\r\n", stdout);
    exit(1);
}
// 자식 프로세스의 종료 여부 확인
void read_childpro(int _signal){
    pid_t pid;
    int status;
    pid = waitpid(-1, &status, WNOHANG);
    printf("remove process id : %d\r\n", pid);
}