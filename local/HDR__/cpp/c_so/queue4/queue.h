#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"

template<typename T>
class Queue {
private:
	static const int QUEUE_SIZE;
	
	Array<T> arr_;
	int front_;
	int rear_;
	
public:
	explicit Queue(int size = QUEUE_SIZE);
	//Queue(const Queue<T>& rhs);
	//~Queue();
	
	//Queue<T>& operator=(const Queue<T>& rhs);
	
	void push(const T& data);
	T pop();
	
	bool isFull() const;
	bool isEmpty() const;
};

#include <cassert>
#include "array.h"

template<typename T>
const int Queue<T>::QUEUE_SIZE = 100;

template<typename T>
Queue<T>::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}
/*
template<typename T>
Queue<T>::Queue(const Queue<T>& rhs)
: arr_(rhs.arr_), front_(rhs.front_), rear_(rhs.rear_)
{

}

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
	arr_ = rhs.arr_;
	front_ = rhs.front_;
	rear_ = rhs.rear_;
	
	return *this;
}

*/
template<typename T>
void Queue<T>::push(const T& data)
{
	assert(!isFull());
	
	arr_[rear_] = data;
	rear_ = (rear_ + 1) % arr_.size();
}

template<typename T>
T Queue<T>::pop()
{
	assert(!isEmpty());
	
	int index = front_;
	front_ = (front_ + 1) % arr_.size();
	return arr_[index];
}

template<typename T>
bool Queue<T>::isFull() const
{
	return (rear_ + 1) % arr_.size() == front_;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return front_ == rear_;
}

#endif

