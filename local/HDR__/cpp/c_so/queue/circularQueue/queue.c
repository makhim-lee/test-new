#include "queue.h"

void initQueue(Queue *pq, int size)
{
    pq->pArr = malloc(sizeof(int) * size);
    pq->size = size;
    assert(pq->pArr );
    pq->front = 0;
    pq->rear = 0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, int data)
{
    // if(pq->rear == pq->size){
    //     fprintf(stderr, "full\n");
    //     exit(1);
    // }
    assert((pq->rear + 1) % pq->size != pq->front);
    pq->pArr[pq->rear] = data;
    pq->rear = (pq->rear + 1) % pq->size;
}

int pop(Queue *pq)
{
    if(pq->front == pq->size){
        fprintf(stderr, "NUll\n");
        exit(1);
    }
    int i = pq->front;
    pq->front = (pq->front + 1) % pq->size;
    return pq->pArr[i];
}

