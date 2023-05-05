#include<iostream>
#include"array.h"

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    Array arr1(nums, 5);
    Array arr2;
    Array arr3(100);   //Array arr3 = 100;  ??? 
    const Array arr4 = arr1;

    arr2 = arr1;

    if(arr1 == arr2) std::cout << "equal" <<std::endl;
    else std::cout << "not equal" << std::endl;

    for(int i = 0; i < arr1.size(); ++i){
        std::cout << arr1[i] <<std::endl; // arr.operator[](i);
    }

    // arr4[0] = 0;
    return 0;
}
