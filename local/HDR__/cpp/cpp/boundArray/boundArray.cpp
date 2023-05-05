#include<cassert>
#include"safeArray.h"
#include"boundArray.h"

BoundArray::BoundArray(const int size)
: SafeArray(5), low_(0)
{

}

BoundArray::BoundArray(const int *Arr, const int size)
: SafeArray(Arr, size), low_(0)
{

}

BoundArray::BoundArray(const BoundArray& rhs)
: SafeArray((SafeArray)rhs), low_(rhs.low_)
{

}

BoundArray::BoundArray(const int lower, const int upper)
: SafeArray(upper - lower), low_(lower)// :SafeArray(upper - low), low_(low)
{
    // for(int i = 0; i < (upper - low); ++i){
    //     Array::pArr_[i] = i + 1;
    // }
}
BoundArray::~BoundArray(){

}

BoundArray& BoundArray::operator=(const BoundArray& rhs){
    this->SafeArray::operator=((SafeArray)rhs);
    low_ = rhs.low_;
    return *this;
    //this->Array::operator((Array)rhs);
    //return *this
}
bool BoundArray::operator==(const BoundArray&rhs)const{
    return this->SafeArray::operator==((SafeArray)rhs) && low_ == rhs.low_;
    // return (SafeArray)*this == (SafeArray)rhs && low_ == rhs.low_;
}
int BoundArray::lower() const{
    return low_;
}
int BoundArray::upper() const {
    return low_ + /*this->Array::*/size();
}