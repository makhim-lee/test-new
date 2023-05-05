#include<cassert>
#include"safeArray.h"

//const int SafeArray::SAFE_ARRAY_SIZE = 100;

SafeArray::SafeArray(int size)    
: Array(size)                   // 부모쪽에 생성자호출
{
}
SafeArray::SafeArray(const int *pNum, int size)
: Array(pNum, size)
{
}
/*  
SafeArray::SafeArray(const SafeArray& rhs)
: Array((Array)rhs)     // slicing 자식객체에서 부모객체 관련되 부분만 호출?
{

}
SafeArray::~SafeArray(){

}
SafeArray& SafeArray::operator=(const SafeArray& rhs){
    this->Array::operator=(static_cast<Array>(rhs));    //자식객체 안에 있는 부모객체의 멤버함수를 this로 호출 //slicing 
    return *this
}
*/

bool SafeArray::operator==(const SafeArray& rhs) const{
    return this->Array::operator==(static_cast<Array>(rhs));  
    // return (Array)*this == (Array)rhs;
}

int& SafeArray::operator[](int index){
    assert(index >= 0 && index < this->Array::size_);   // protected 으로 부모 private에 접근
    return this->Array::operator[](index);  // 정형적인 상속 형태
}

const int& SafeArray::operator[](int index)const{
    assert(index >= 0 && index < size()/*this->Array::size()*/);
    return this->Array::operator[](index);
}