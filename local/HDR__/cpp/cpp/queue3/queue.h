#ifndef Queue_H
#define Queue_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include"array.h"

class Queue{
private:
    static const int QUEUE_SIZE;
    Array arr_;
    //int *pArr;
    //int size_;
    int front_;
    int rear_;
public:
    explicit Queue(int size = QUEUE_SIZE);
    //Queue(const Queue& rhs);
    //~Queue();

    //Queue& operator=(const Queue& rhs);
    void push(int data);
    int pop();

    bool isFull() const;
    bool isEmpty() const;
};

#endif