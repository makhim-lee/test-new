#include "queue.h"

void initQueue(Queue *ps, int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    ps->size = size;
    assert(ps->pArr );
    ps->front = 0;
    ps->rear = 0;
}

void cleanupQueue(Queue *ps)
{
    free(ps->pArr);
}

void push(Queue *ps, int data)
{
    if(ps->rear == pq->size){
        fprintf(stderr, "full\n");
        exit(1);
    }
    ps->pArr[ps->rear] = data;
    ++ps->rear;
}

int pop(Queue *ps)
{
    if(ps->front == pq->size){
        fprintf(stderr, "NUll\n");
        exit(1);
    }
    int i = ps->front;
    ++ps->front;
    return ps->pArr[i];
}

