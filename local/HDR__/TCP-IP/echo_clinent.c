#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
void error_handling(const char*);
int main(int agrc, const char* argv[])
{ 
    int sock = 0; // connet serv fd
    char message[BUFSIZ] = {'\0' };
    int str_length = 0;
    struct sockaddr_in serv_addr;
    if(agrc != 3) {
            puts("ECHO_CLIENT 127.0.0.1 999\r\n"); 
            exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1) error_handling("socker() error");

    memset(&serv_addr, 0 , sizeof serv_addr);  // all reset to '0'
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // ip주소 htons()가 받을수 있게 수정
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof serv_addr) == -1) {
        error_handling("connect() error");
    }else puts("conneted ...\r\n");

    while(1){
        fputs("Input your message(Q to quit)!! : ", stdout);
        fgets(message, BUFSIZ, stdin);
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n")) break;
        write(sock, message, BUFSIZ - 1);
        str_length = read(sock, message, BUFSIZ - 1);
        message[str_length] = 0; //insert null string 
        printf("Message form server : %s\r\n", message);
    }
    close(sock);
    return 0;
}

void error_handling(const char* _message){
    fputs(_message, stdout);
    fputs("\r\n", stdout);
    exit(1);
}
