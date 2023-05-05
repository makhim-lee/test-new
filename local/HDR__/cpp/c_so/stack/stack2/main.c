#include<stdio.h>


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



