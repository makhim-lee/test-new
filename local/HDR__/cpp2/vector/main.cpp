#include<iostream>
#include"vector.h"

int main(){
    iot::Vector<int> v1;
    iot::Vector<int> v2(10);
    //iot::vector v2(10, int(0));

    int nums[] = {1, 2, 3, 4, 5};

    iot::Vector<int> v3(nums, nums + 5);
    iot::Vector<int> v4 = v3;

    v1 = v4;
    if(v1 == v4){
        
    }else{

    }

    for(iot::Vector<int>::size_type i = 0; i != v1.size(); ++i){
        std::cout<<v1[i]<<std::endl;
    }

    for(iot::Vector<int>::const_iterator it = v1.begin(); it != v1.end(); ++it){
        std::cout<<*it<<std::endl;
    }
    return 0;
}