#ifndef Queue_H
#define Queue_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>

class Queue{
private:
    int *pArr;
    int size;
    int front;
    int rear;
public:
    Queue(int size);
    ~Queue();
    void push(int data);
    int pop();
};

#endif