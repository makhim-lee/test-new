#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

void error_handling(const char*);
int main(int argc, const char* argv[])
{
    int serv_sock = 0;
    int clnt_sock = 0;
    char message[BUFSIZ] = {'\0', };
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = 0u;

    if (argc != 2)  {
        puts("ECHO_SERVER 9999");
        exit(1);
    }
    //socket() 생성
    serv_sock = socket(AF_INET, SOCK_STREAM, 0); // serv_sock FD
    if(serv_sock == -1){
        error_handling("socket 생성오류");
    }
    memset(&serv_addr, 0 , sizeof serv_addr);
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //127.0.0.1 + my_ip
    serv_addr.sin_port = htons(atoi(argv[1]));
    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof serv_addr) == -1) {
        error_handling("bind() error");
    }
    if(listen(serv_sock, 5) == -1) error_handling("listen() error");
    //대기중에 있다가 클라이언트 접근
    clnt_addr_size = sizeof (clnt_addr);  // 재초기화
    int str_len = 0;
    for (int i = 0; i < 5; i++){ // 5개의 clnt resive
        clnt_sock /*clinet fd*/ = accept(serv_sock, (struct sockaddr*)&serv_addr, &clnt_addr_size);
        if(clnt_sock == -1) error_handling("clint_sock - accept() error");
        else {
            printf("Connected clinet %d\r\n", i + 1);
            while ((str_len = read(clnt_sock, message, BUFSIZ)) != 0) //문자열길이로 데이터 유무 판단
            {
                write(clnt_sock, message, str_len);
            }
            close(clnt_sock);
        }
    }
    close(serv_sock);
    return 0;
}

void error_handling(const char* _message){
    fputs(_message, stdout);
    fputs("\r\n", stdout);
    exit(1);
}
