#include <iostream>
#include<algorithm>
#include"median.h"
using std::cin; using std::cout;
using std::endl;
using std::vector;

int median(const vector<int>& vec){
    vector<int> nums = vec;
    //sorting
    std::sort(nums.begin(), nums.end());

    const vector<int>::size_type size = nums.size();
    int result = (size /2 )? nums[size/2] : (nums[size/2] + nums[size/2 - 1])/2;
    return result;
}