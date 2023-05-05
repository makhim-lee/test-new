#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int front;
int rear;

void push(int data);
int pop(void);

#endif