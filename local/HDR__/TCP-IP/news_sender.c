#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>

#define TTL 64

void error_handling(const char*);
/*server -> sender
  receiver -> client*/

int main(int argc, const char** argv)
{
    int send_sock = 0; // socket() 변수
    int time_live = TTL; //64
    /*
    *HDD File 클라이언트들에게 일방적으로 전송
    *FILE 구조체 : 주소는 HDD
    *fp
    */
    FILE * fp = NULL;
    char buffet[BUFSIZ] = {'\0',};
    struct sockaddr_in multi_addr;
    memset(&multi_addr, 0, sizeof multi_addr); //reset

    if(argc != 3)error_handling("NEWS_SENDER 169.168.0.1 9999");
//TODO socket()
    send_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(send_sock == -1) error_handling("socket() error");

    multi_addr.sin_family = AF_INET;
    multi_addr.sin_addr.s_addr = inet_addr(argv[1]); // 192.168.0.1 <- chage 32bit
    multi_addr.sin_port = htons(atoi(argv[2])); //16bit
//TODO setting TTL, setsockopt()
    setsockopt(send_sock, IPPROTO_IP, IP_MULTICAST_TTL, (void*)&time_live/*TTL*/, sizeof time_live);
    if((fp = fopen("news.txt", "r")) == NULL) error_handling("file dose not ");
    while (!feof(fp)) //EdnOfFile -->eof
    {
        fgets(buffet,BUFSIZ, fp); //stdin == keyboard , fp == file(news.txt)
//TODO sendto()전송
        sendto(send_sock, buffet, strlen(buffet), 0, (struct sockaddr*)&multi_addr, sizeof multi_addr);
        sleep(2); 
    }
    fclose(fp); //file
    close(send_sock); // socket
    
    return 0;
}

void error_handling(const char* _message){
    fputs(_message, stderr/*err 출력*/);
    fputs("\r\n", stderr);
    exit(1);
}
