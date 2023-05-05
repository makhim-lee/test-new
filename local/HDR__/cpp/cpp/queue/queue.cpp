#include "queue.h"

Queue::Queue(int size)
{
     this->pArr = new int[size];
     this->size = size;
    assert( this->pArr );
     this->front = 0;
     this->rear = 0;
}

Queue::~Queue()
{
    delete[] this->pArr;
}

void Queue::push(int data)
{
    if( this->rear ==  this->size){
        fprintf(stderr, "full\n");
        exit(1);
    }
     this->pArr[ this->rear] = data;
    ++ this->rear;
}

int Queue::pop()
{
    if( this->front ==  this->size){
        fprintf(stderr, "NUll\n");
        exit(1);
    }
    int i =  this->front;
    ++ this->front;
    return  this->pArr[i];
}

