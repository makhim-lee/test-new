#include<stdio.h>
#include"stack.h"



int main(void)
{
    Stack s1, s2; // Stack stacks[100]

    // s1.tos = 0;
    // s2.tos = 0; 

    initStack(&s1);
    initStack(&s2);

    push(&s1, 100);
    push(&s1, 200);
    push(&s1, 300);

    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));
    printf("%d\n", pop(&s1));

    pop(&s1);

    
    push(&s2, 600);
    push(&s2, 500);
    push(&s2, 400);

    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));
    printf("%d\n", pop(&s2));
    return 0;
}