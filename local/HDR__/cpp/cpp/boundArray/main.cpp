#include<iostream>
#include"boundArray.h"

int main()
{
    BoundArray arr1;                //BoundArray arr1(100);
    BoundArray arr(20);
    int nums[] = {1, 2, 3, 4, 5};
    BoundArray arr3(nums, 5);
    BoundArray arr2(1, 8);          // index[1, 8) 1, 2, 3, 4, 5, 6, 7

    arr1 = arr2;

    if(arr1 == arr2){

    }else{

    }

    for(int i = arr1.lower(); i<arr1.upper(); ++i){
        arr2[i] = i;
    }

    for (int i = arr2.lower(); i<arr2.upper(); ++i){
        std::cout<<"arr2["<<i<<"] : "<<arr2[i]<<std::endl;
    }
    return 0;
}