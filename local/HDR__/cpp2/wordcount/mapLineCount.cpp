#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main(){

   
    map <string, vector<int> > wordCounts;
    string s;

    int LineNumber = 1;
    while(getline(cin, s)){
        vector<string> v = wordCounts.split(s);
        for(auto it = v.cbegin(); it != v.cend(); ++it){
            wordCounts[*it].push_back(LineNumber);
        }
        ++LineNumber;
    }

    map<string, vector<int> >::const_iterator it;
    for(it = wordCounts.cbegin(); it != wordCounts.cend(); ++it){
        cout<<it->first<<" : ";
        for(auto it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2){
            cout << *it2<<", ";
        }
    }
   

    for(map<string, vector<int> >::const_iterator it = wordCounts.cbegin(); it != wordCounts.cend(); ++it){
        cout << it ->first<< " : "<<it->second <<endl;
    }
    
    return 0;

}