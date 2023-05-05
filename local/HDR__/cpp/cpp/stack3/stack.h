#ifndef STACK_H
#define STACK_H
#include<ostream>
#include"array.h"
class Stack{   
//friend std::ostream& operator<<(std::ostream& out, const Stack& rhs);

private:
    static const int STACK_SIZE = 100;
    //int *pArr_;
    //int size_;
    Array arr_;    //has-a
    int tos_;

    Stack(const Stack& rhs);
    Stack& operator=(const Stack& rhs);
public:
    explicit Stack(int size = STACK_SIZE);  
    //~Stack();

    void push(int data);
    int pop();
    
    bool isFull()const;
    bool isEmpty()const;
    
};
#endif