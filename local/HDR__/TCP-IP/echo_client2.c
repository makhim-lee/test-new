#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc, const char * argv[])
{
    int sock = 0;
    char message[BUFSIZ] = {'\0', };
    int string_length = 0;
    int receive_length = 0;
    int receive_count = 0;
    struct sockaddr_in serv_addr;
    if(argc != 3){
        puts("ECHO_CLIENT2 127.0.0.1 9999\r\n");
        exit(1);
    }
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        puts("socket() error");
        exit(1);
    }
    memset(&serv_addr, 0, sizeof serv_addr); //reset
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); //127.0.0.1 --> int_32
    serv_addr.sin_port = htons(atoi(argv[2])); // 9999--> int_16
    if(connect(sock, (const struct sockaddr*)&serv_addr, sizeof serv_addr)){
        puts("connect() errer\r\n");
        exit(1);
    }else{
        puts("Connected ...\r\n");
    }
    while (1)
    {
        fputs("Input your message(Q to quit) : ", stdout); //stdout -> 2 (FD)
        fgets(message, BUFSIZ, stdin); // message save input char
        if(strcmp(message, "q\n") || strcmp(message, "Q\n")){
            puts("Good bye\r\n");
            break;
        }
        string_length = write(sock, message, strlen(message)); // save strlen 

        receive_length = 0; //set "0" agin
        while(string_length > receive_length){
            receive_count = read(sock, &(message[receive_length]), BUFSIZ - 1);
            if(receive_count == -1) puts("read error\r\n");
            receive_length += receive_count;
        }
        message[receive_length] = '\0'; // insert null str last
        fprintf(stdout, "Message from Server : %s\r\n", message);
    }
    close(sock);  //close input 'q'
    
    return 0;
}