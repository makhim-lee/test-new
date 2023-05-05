#ifndef STACK_H
#define STACK_H
#include<ostream>

class Stack{   
//friend std::ostream& operator<<(std::ostream& out, const Stack& rhs);

private:
    static const int STACK_SIZE = 100;
    int *pArr_;
    int size_;
    int tos_;

    Stack(const Stack& rhs);
    Stack& operator=(const Stack& rhs);
public:
    explicit Stack(int size = STACK_SIZE);  
    ~Stack();

    void push(int data);
    int pop();
    
    bool isEmpty()const;
    bool isFull()const;
};
#endif