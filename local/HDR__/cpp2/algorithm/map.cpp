#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool isspace(char c){
    return c == ' ' || c == '\t' || c == '\n';
}
bool space(char c){ // 내장 라이브 isspace 와 오버로딩 되어서 이름을 바꿔줌 
    return isspace(c);
}
bool isNotSpace(char c){
    return !isspace(c);
}


void split(const string& s, vector<string>& words){
    
    string::const_iterator it = s.begin();

    while(it != s.end()){
        it = find_if(it, s.end(), isNotSpace);
    
        string::const_iterator it2;
        it2 = find_if(it, s.end(), space);

        if(it != s.cend()){
            words.push_back(string(it, it2));
        }        
        it = it2;
    }
}