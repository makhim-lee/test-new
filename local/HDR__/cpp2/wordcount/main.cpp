#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
    vector<string> words;
    vector<int> counts;
    string word;

    vector<string>::size_type i;
    while(cin){ //istream --> bool
        cin>>word;
        for(i = 0; i < words.size(); ++i){  // vector 공간 할당
            if(word == words[i])break;
        }
        if(i == words.size()) {
            words.push_back(word);
            counts.push_back(1);
        }else ++counts[i];
    }

    for(i = 0; i < words.size(); ++i){
        cout<<words[i]<<" : " <<counts[i]<<endl;
    }
    return 0;
}