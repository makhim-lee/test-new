#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<assert.h>
#include<stdio.h>
#include<arpa/inet.h>  //struct sockaddr
#include<pthread.h>  // pthread_t , mutex

int dataSockets[100];
int count;
pthread_mutex_t mutex;

void* clientProc(void *arg);

int main(void)
{
    pthread_mutex_init(&mutex, NULL);
    int servSocket = socket(AF_INET, SOCK_STREAM, 0);  //open()
    // int fd = open(...); file descriptor 파일 기술자 
    // close(fd);
    assert(servSocket != -1);

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(80); 

    assert(bind(servSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) != -1); //주소체계에 따라 사이즈가 다를수 있음으로 사이즈도 받음
    //bind(servSocket, AF_INET, &servAddr, sizeof(servAddr));  // (*void)로 라이브러리 만들었을시
    
    assert(listen(servSocket, 5) != -1); //서버크기가 거지면 5 이상 줌 
    
    for(;;){
        struct sockaddr_in clientAddr;
        int len;

        int dataSocket = accept(servSocket, (struct sockaddr *)&clientAddr, &len);//클라이언트따라 다른 주소가 들어감으로 const X
        assert(dataSocket != -1);
        //dataSockets[i] = dataSocket
        printf("client ip : %s\n", inet_ntoa(clientAddr.sin_addr));
pthread_mutex_lock(&mutex);
        dataSockets[count] = dataSocket;
        ++count;
pthread_mutex_unlock(&mutex);
        //create Thread! call clientProc!
        pthread_t pthread_id;
        pthread_create(&pthread_id, NULL, &clientProc, &dataSocket);
        pthread_detach(pthread_id);

    }
    close(servSocket);
    pthread_mutex_destroy(&mutex);
    return 0;
}

void* clientProc(void *arg){ // 임의의 인자를 받고 임의의 값을 반환
    int dataSocket = *((int *)arg);
    char buf[1024];
    int nread;
    while((nread = read(dataSocket, buf, 1024)) ){  //0~1024bit 가변으로 읽음 //파일의 끝에서 0이됨(반환 값 체크)
        assert(nread != -1);
            //write(dataSocket, buf, nread);  // 100bit 만큼 읽음
pthread_mutex_lock(&mutex);
        for(int i = 0; i < count ; ++i){
             write(dataSockets[i], buf, nread);
        }
pthread_mutex_unlock(&mutex);
        }
pthread_mutex_lock(&mutex);
    for(int i = 0; i < count; ++i){
        if(dataSockets[i] == dataSocket){
            for (int j = i; j < count - 1; ++j){
                dataSockets[j] = dataSockets[j + 1];
            }
            break;
        }
    }
    --count;
pthread_mutex_unlock(&mutex);
    close(dataSocket);

    return NULL;
}


//system call
//open(), close(), read(), write(), ioctl()


// int bind(int fd, const struct sockaddr *addr, int size){
//     int family = *(int *)addr;
//     if (family == AF_INET){
//         // addr = *((int *)addr + 1);
//         // port = *(short *)((int *)addr + 2);
//         //  ......
//         struct sockaddr_in addr_in = (struct sockaddr_in)(*addr);
//         ??? = addr_in.sin_addr;
//         ??? = addr_in.sin_port;
//     }else if (family == ??){
//     }
// }