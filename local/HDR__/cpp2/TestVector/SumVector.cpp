//1. vector<int> v <-- rand 100
//sum.avr (iterator)
#include<iostream>
#include<vector>
#include<random>


using namespace std;

int main()
{
    vector<int> v(100);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 99);
    
    for(int i = 0; i < 100; ++i){
        int num = dis(gen);
        v.push_back(num);
    }
    int sum = 0;
    vector<int>::const_iterator it; //auto it
    for (it = v.cbegin(); it != v.cend(); ++it){
        sum += *it;
    }
    double aver = (double)sum / v.size() * 2;
    cout<< sum<<"/"<<v.size()/2<<"=" <<aver<<endl;
    return 0;
}