#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array{
private:
    T *pArr_;            
          
protected:
    static const int ARRAY_SIZE; 
    
    int size_;
    
public:
	// Array<T> *operator&() { return this; }
	// const Array<T> *operator&() const { return this; }

    explicit Array(int size = Array<T>::ARRAY_SIZE);   
    Array(const T *pArr, int size = ARRAY_SIZE);
    Array(const Array<T>& rhs);
    virtual ~Array();

    Array<T>& operator=(const Array<T>& rhs);

    bool operator==(const Array<T>& rhs)const;

    virtual T& operator[](int index);   //일반객체
    virtual const T& operator[](int index) const;  //상수객체 
    
    int size() const;
};


#include<cassert>

template <typename T>
const int Array<T>::ARRAY_SIZE = 100;

template <typename T>
Array<T>::Array(int size)
: pArr_(new T[size]), size_(size)
{
    assert(pArr_);
    
}

template <typename T>
Array<T>::Array(const T *pArr, int size)
: pArr_(new T[size]), size_(size)
{
    assert(pArr_);
    
    for (int i = 0; i < size; ++i){
        pArr_[i] = pArr[i];
    }
}

template <typename T>
Array<T>::Array(const Array<T>& rhs)
: pArr_(new T[rhs.size_]), size_(rhs.size_)
{
    assert(pArr_);

    for (int i = 0; i < rhs.size_; ++i){
        pArr_[i] = rhs.pArr_[i];
    }
}

template <typename T>
Array<T>::~Array(){
    delete [] pArr_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if(this != &rhs){
        delete [] pArr_;
        pArr_ = new T[rhs.size_];
        assert(pArr_);
        size_ = rhs.size_;

        for (int i = 0; i < rhs.size_; ++i){
            pArr_[i] = rhs.pArr_[i];
        }
    }
    
    return *this;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& rhs) const
{
    if(size_ != rhs.size_)return false;
    int i;
    for (i = 0; i < rhs.size_; ++i){
        if (pArr_[i] != rhs.pArr_[i]) break;
    }
    return (i == rhs.size_);
}

template <typename T>
T& Array<T>::operator[](int index)
{
    return pArr_[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
    return pArr_[index];
}

template <typename T>
int Array<T>::size() const{
    return size_;
}


#endif
