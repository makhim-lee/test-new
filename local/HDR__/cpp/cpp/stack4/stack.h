#include<cassert>
#include<ostream>
#include"array.h"
#include"string.h"
#include"complex.h"


#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack{   

private:
    //static const int STACK_SIZE = 100;
 
    Array<T> arr_;    //has-a
    int tos_;

    Stack(const Stack<T>& rhs);
    Stack<T>& operator=(const Stack<T>& rhs);
public:
    explicit Stack(int size = 100/*Stack<T>::STACK_SIZE*/);  


    void push(const T&);  //class 를 받을떄 복사생성되는걸 막기위해 레퍼런스함
    T pop();   //레퍼런스해도 작동하지만 ~~~
    
    bool isFull()const;
    bool isEmpty()const;
    
};

//template<typename T>
//const int Stack<T>::STACK_SIZE = 100;
template<typename T>
Stack<T>::Stack(int size)
: arr_(size), tos_(0)
{
}

// Stack::~Stack(){
//     delete [] pArr_;
// }
template<typename T>
void Stack<T>::push(T data)
{
    assert(!isFull());
    arr_[tos_] = data;
    ++tos_;
}
template<typename T>
T Stack<T>::pop()
{
    assert(!isEmpty());
    --tos_;
    return arr_[tos_];
}
template<typename T>
bool Stack<T>::isFull()const{
    return tos_ == arr_.size();
}
template<typename T>
bool Stack<T>::isEmpty()const{
    return tos_ == 0;
}


#endif