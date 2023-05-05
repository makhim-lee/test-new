// search algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::search
#include <vector>       // std::vector
#include <algorithm>    // std::transform

int square(int i){
    return i * i;
}


int main(){
    int nums[] = {50, 30, 100, 90, 60, 40, 10, 20, 70, 80};
    std::vector<int> v(nums, nums + 10);

    int pattern[] = {90, 60, 40};
    std::vector<int>::const_iterator it = std::search(v.cbegin(), v.cend(), pattern, pattern + 3);

    if( it!=v.cend()){
        //found
    }else{
        //not found;
    }

    std:: vector<int> result;
    std::transform(v.cbegin(), v.cend(), std::back_inserter(result), square);

    return 0;
}



bool mypredicate (int i, int j) {
  return (i==j);
}

int main () {
    std::vector<int> haystack;

    // set some values:        haystack: 10 20 30 40 50 60 70 80 90
    for (int i=1; i<10; i++) haystack.push_back(i*10);

    // using default comparison:
    int needle1[] = {40,50,60,70};
    std::vector<int>::iterator it;
    it = std::search (haystack.begin(), haystack.end(), needle1, needle1+4);

    if (it!=haystack.end())
    std::cout << "needle1 found at position " << (it-haystack.begin()) << '\n';
    else
    std::cout << "needle1 not found\n";

    // using predicate comparison:
    int needle2[] = {20,30,50};
    it = std::search (haystack.begin(), haystack.end(), needle2, needle2+3, mypredicate);

    if (it!=haystack.end())
    std::cout << "needle2 found at position " << (it-haystack.begin()) << '\n';
    else
    std::cout << "needle2 not found\n";

    return 0;
}