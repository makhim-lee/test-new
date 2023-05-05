#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct queue{
    int *pArr;
    int size;
    int front;
    int rear;
} Queue;

void initQueue(Queue *pq, int size);
void cleanupQueue(Queue *pq);

void push(Queue *pq, int data);
int pop(Queue *pq);

#endif