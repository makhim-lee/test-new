#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <arpa/inet.h>
#include <pthread.h>

int dataSockets[100];
int count;
pthread_mutex_t mutex;

void *clientProc(void *arg);

int main(void) {
    pthread_mutex_init(&mutex, NULL);
    int servSocket = socket(AF_INET, SOCK_STREAM, 0);
    assert(servSocket != -1);

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(7000);

    assert(bind(servSocket, (struct sockaddr*)&servAddr, sizeof(servAddr)) != -1);
    assert(listen(servSocket, 5) != -1);

    for (;;) {
        int dataSocket = accept(servSocket, NULL, NULL);
        assert(dataSocket != -1);

        pthread_mutex_lock(&mutex);
        dataSockets[count] = dataSocket;
        ++count;
        pthread_mutex_unlock(&mutex);

        pthread_t pthread_id;
        pthread_create(&pthread_id, NULL, &clientProc, &dataSocket);
        pthread_detach(pthread_id);
    }

    close(servSocket);
    pthread_mutex_destroy(&mutex);
    return 0;
}

void* clientProc(void *arg){ // 임의의 인자를 받고 임의의 값을 반환
    int dataSocket = *(int *)arg;
        char buf[1024];
        int nread;
        while((nread = read(dataSocket, buf, 1024)) ){  //0~1024bit 가변으로 읽음 //파일의 끝에서 0이됨(반환 값 체크)
            assert(nread != -1);
            //write(dataSocket, buf, nread);  // 100bit 만큼 읽음
pthread_mutex_lock(&mutex);
            for(int i = 0; i < count ; ++i){
                write(dataSockets[i], buf, nread);
            }
        }
pthread_mutex_unlock(&mutex);
pthread_mutex_lock(&mutex);
    for(int i = 0; i < count; ++i){
        if(dataSockets[i] == dataSocket){
            for (int j = i; j < count - 1; ++j){
                dataSockets[j] = dataSockets[j + 1];
            }
            --count;
            break;
        }
    }
pthread_mutex_unlock(&mutex);
    close(dataSocket);

    return NULL;
}