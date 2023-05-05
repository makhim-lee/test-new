#include<algorithm>
#include<iostream>
#include<vector>
#include<list>
#include<numeric> //accumulate

bool fail(int score){
    return score < 60;
}

bool isPass(int score){
    //return score > 60;
    return !fail(score); // 함수재사용
}

bool isEqualZero(int value){
    return value == 0;
}


int main() {
    int nums[] = {50, 20, 40, 30, 100, 80, 90, 70, 60, 10};
    std::vector<int> v1(nums, nums + 10);

    std::vector<int> v2 = v1;
    v2.erase(std::remove(v2.begin(), v2.end(), 100), v2.end());

    int sum = std::accumulate(v2.begin(), v2.end(), 100, v2.end());

    double nums2[] = {1.1, 1.2, 1.3, 1.4, 1.5};
    double sum2 = std::accumulate(nums2, nums2 + 5, 0.0); // 템플릿된 함수를 사용할때 타입을 주의할것 0.0 --> 0  xxxx
    
    std::vector<int> v3 = v1;
    v3.erase(std::remove_if(v3.begin(), v3.end(), fail), v3.end());

    std::vector<int> v4;
    //std::copy(v1.begin(), v1.end(), v4.end()); // vector size 는 가변이라 v4.end 고정해버리면 안됨
    std::copy(v1.cbegin(), v1.cend(), std::back_inserter(v4)); // push back 처럼 작동됨

    std::vector<int> v5;
    std::copy_if(v1.cbegin(), v1.cend(), std::back_inserter(v5), isPass);

    // std::vector<int>::const_iterator it;
    auto it = std::find(v1.cbegin(), v1.cend(), 100);
    if(it != v1.end()){
        std::cout<<"found"<<std::endl;
    }else{
        std::cout<<"not found"<<std::endl;
    }

    auto it2 = std::find_if(v1.cbegin(), v1.cend(), isEqualZero);
    if(it2 != v1.end()){
        std::cout<<"found"<<std::endl;
    }else{
        std::cout<<"not found"<<std::endl;
    }

    std::list<int> list(v1.cbegin(), v1.cend());
    //std::equal(v1.cbegin(), v1.cend(), nums) == true;
    if(std::equal(v1.cbegin(), v1.cend(), list.cbegin()) == true){
        std::cout<<"v1 and list are equal elements."<<std::endl;
    } else{
        std::cout<<"v1 and list are not equal elemets"<<std::endl;
    }

    std::string str = "civic";
    if(std::equal(str.cbegin(), str.cend(), str.crbegin()) == true){
        //
    } 
    for (auto it = v1.crbegin(); it != v1.crend(); ++it){ // r ->리버스
        std::cout<< *it << std::endl;
    }
    std::vector<int> v6(v1.crbegin(), v1.crend());
    

    std::replace(v6.begin(), v6.end(), 50, 0);
    std::replace_if(v6.begin(), v6.end(), fail, 0);

    std::vector<int> v7;
    std::remove_copy_if(v1.cbegin(), v1.cend(), std::back_inserter(v7), fail);




    return 0;
}




