#include<stdio.h>
#define STACK_SIZE 100

int stack[STACK_SIZE]; // 전역변수는 초기화 안해도 됨 
int tos; // top of stack

void push(int data)
{
    stack[tos] = data;
    ++tos;
}

int pop(void)
{
    --tos;
    return stack[tos];
}

void push(int data);
int pop(void);

int main(void)
{
    push(100);
    push(200);
    push(300);

    printf("lst pop() ; %d\n", pop());
    printf("lst pop() ; %d\n", pop());
    printf("lst pop() ; %d\n", pop());
    return 0;
}

