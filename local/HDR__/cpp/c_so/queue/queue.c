#include<stdio.h>

#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int front;
int rear;

void push(int data)
{
    queue[rear] = data;
    ++rear;
}

int pop(void)
{
    int i = front;
    ++front;
    return queue[i];
}

int main(void)
{
    push(100);
    push(200);

    printf("%d\n", pop());

    push(300);

    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}