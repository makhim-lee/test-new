#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#define QUEUE_SIZE 100

typedef struct queue{
    int array[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *ps);

void push(Queue *ps, int data);
int pop(Queue *ps);

#endif