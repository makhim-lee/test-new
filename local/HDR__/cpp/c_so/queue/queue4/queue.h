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

void initQueue(Queue *ps, int size);
void cleanupQueue(Queue *ps);

void push(Queue *ps, int data);
int pop(Queue *ps);

#endif