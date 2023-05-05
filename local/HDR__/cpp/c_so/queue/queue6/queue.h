#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue{
    int *pArr;
    int eleSize;
    int front;
    int rear;
} Queue;

void initQueue(Queue *ps, int size, int eleSize);
void cleanupQueue(Queue *ps);

void push(Queue *ps, const void *pData);

void pop(Queue *ps, void *pData);

#endif