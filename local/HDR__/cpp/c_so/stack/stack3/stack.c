#include<stdio.h>
#include<stdlin.h>
#include "stack.h"

void initStack(Stack *ps)
{
    ps -> tos = 0;
}

void push(Stack *ps,int data)
{
    //pull ??
    if (ps->tos == STACK_SIZE){
        fprintf(stderr, "stack is full\n");
        exit(1);
    }
    ps -> array[ps -> tos] = data;
    ++ps -> tos;
}

int pop(Stack *ps)
{
    //empty ??
    if (ps->tos == 0){
        fprintf(stderr, "stack is empty\n");
        exit(2);
    }

    --ps -> tos;
    return ps -> array[ps -> tos];
}
