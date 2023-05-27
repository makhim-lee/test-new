#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>

int main(int argc, const char* argv[])
{
    int tcp_socket = 0;
    int udp_socket = 0;
    socklen_t option_len;
    int state = 0;
    int socket_type;
    
    tcp_socket = socket(PF_INET, SOCK_STREAM, 0);
    udp_socket = socket(PF_INET, SOCK_DGRAM, 0);
    printf("SOCK_STREAM : %d\r\n", SOCK_STREAM);
    printf("SOCK_DGRAM: %d\r\n", SOCK_DGRAM);
    
    getsockopt(tcp_socket, SOL_SOCKET, SO_TYPE, (void*)&socket_type, &option_len);
    printf("socket_type : %d\t opttion_len : %d\r\n", socket_type, option_len);
    return 0;
}