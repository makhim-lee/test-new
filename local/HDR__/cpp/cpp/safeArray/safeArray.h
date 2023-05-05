#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include"Array.h"
//class SafeArray : private Array  
class SafeArray : public Array{   //상속
private:
    //static const int SAFE_ARRAY_SIZE;
public:
    //explicit SafeArray(const int size = SAFE_ARRAY_SIZE);
    explicit SafeArray(const int size = Array::ARRAY_SIZE);
    SafeArray(const int *pNum, int size);
    // ~SafeArray();
    // SafeArray(const SafeArray& rhs, const int size = SAFE_ARRAY_SIZE)
    // SafeArray& operator=(const SafeArray& rhs);
    
    bool operator==(const SafeArray& rhs) const;

    virtual int& operator[](int index); //부모쪽 호출 해도 작동함
    virtual const int& operator[](int index)const;
};

#endif