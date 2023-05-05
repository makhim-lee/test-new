#include<iostream>
#include"array.h"
#include"safeArray.h"

int main()
{
    SafeArray arr1;  //SafeArray arr1(100)
    SafeArray arr2(20);  //SafeArray arr2 = 20; XXX

    int nums[] = {1, 2, 3, 4, 5};
    SafeArray arr3(nums, 5);
    SafeArray arr4 = arr3;

    arr1 = arr3;

    if (arr1 == arr3) std::cout<<"equal"<<std::endl;
    else std::cout<<"not equal"<<std::endl;
    
    for (int i = 0; i < arr1.size(); ++i) std::cout<<arr1[i]<<std::endl;

    //arr1[5] = 0;
    Array arr[5];
    arr[5] = 0;     //boundary check 

    //Array *pArr = &arr1;
    Array *pArr = new SafeArray(num, 5);
    (*pArr)[5] = 0;   

    delete pArr;  // (*pArr).SafeArray::~SafeArray() ~~~ (*pArr)::Array::~Array()
    return 0 ;
}