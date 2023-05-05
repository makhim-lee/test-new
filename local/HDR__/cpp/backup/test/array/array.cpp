#include<cassert>
#include"array.h"
const int Array::ARRAY_SIZE = 100;

Array::Array(const int size)
: pArr_(new int[size]), size_(size)
{
    assert(pArr_);
}
Array::Array(const Array& rhs) 
: pArr_(new int[rhs.size_]), size_(rhs.size_)
{
    assert(pArr_);
    for(int i = 0; i < size_; ++i) pArr_[i] = rhs.pArr_[i];
}

Array::Array(const int *Arr, const int size)
: pArr_(new int[size]), size_(size)
{
    for(int i = 0; i < size_; ++i) pArr_[i] = Arr[i];
}

~Array::Array(){
    delete [] pArr_;
}

Array& Array::operator=(const Array& rhs){
    if(this != &rhs){
        delete [] pArr_;
        Array(rhs);
    }
    return *this;   //<< xx
}

bool Array::operator==(const Array& rhs){
    if (size_ != rhs.size_) return 0;
    else{
        for(int i = 0; i < size_; ++i) {
            if( pArr_[i] != rhs.pArr_[i]) return 0;
        }
    }
    return 1;
}

bool Array::operator!=(const Array& rhs){
    return !this->operator==(rhs);
}

int& Array::operator[](const int index){
    return pArr_[index];
}
const int& Array::operator[](const int index){
    return pArr_[index];
}

int Array::size(){
    return size_
}

int& 