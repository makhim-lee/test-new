#include "queue.h"


void initQueue(Queue *ps, int size, int eleSize)
{
    ps->pArr = malloc(eleSize * size);
    ps->eleSize = eleSize;
    ps->front = 0;
    ps->rear = 0;
}

void cleanupQueue(Queue *ps)
{
    free(ps->pArr);
}

void push(Queue *ps, const void *pData)
{
    
    memcpy( (unsigned char *)ps->pArr + ps->rear * ps->eleSize, pData, ps->eleSize);
    //ps->pArr[ps->rear] = data;
    ++ps->rear;
}

void pop(Queue *ps, void *pData)
{
    
    memcpy(pData, (unsigned char *)ps->pArr + ps->front * ps->eleSize, ps->eleSize);
    ++ps->front;
}

