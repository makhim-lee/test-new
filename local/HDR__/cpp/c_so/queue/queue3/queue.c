#include "queue.h"

void initQueue(Queue *ps)
{
    ps -> front = 0;
    ps -> rear = 0;
}

void push(Queue *ps,const int data)
{
    ps->array[ps->rear] = data;
    ++ps->rear;
}

int pop(Queue *ps)
{
    int i = ps->front;
    ++ps->front;
    return ps->array[i];
}

