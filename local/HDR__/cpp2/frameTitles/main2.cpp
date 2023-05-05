#include<algorithm> //if (maxLen < line.size())  maxLen = line.size();

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> titles;
    vector<int> counts;
    //read;
    string line;

    vector<string>::size_type i, maxLen = 0;
    while(getline(cin, line)){
        titles.push_back(line);
        //if (maxLen < line.size())  maxLen = line.size();
        maxLen = max(maxLen, line.size());
    }
    
    vector<string> frameTitles;
    frameTitles.push_back(string(maxLen + 4, '*'));
    // for(i = 0; i < titles.size(); ++i){
    //     string space(maxLen - titles[i].size(), ' ');
    //     frameTitles[i] = "* " + titles[i] + space + " *";
    //     frameTitles.push_back( "* " + titles[i] + space + " *");
    // }
    vector<string>::const_iterator it;
    for(it = titles.cbegin(); it != titles.cend(); ++it){
        string space(maxLen - it->size(), ' ');
        frameTitles.push_back("* " + *it + space + " *");       
    }


    frameTitles.push_back(string(maxLen + 4, '*'));
    //frameTitles.push_back(string(maxLen + 4, "*")); 물어보기

    // for(i = 0; i<frameTitles.size(); ++i){
    //     cout<<frameTitles[i]<<endl;
    // }

    for(it = frameTitles.cbegin(); it != frameTitles.cend(); ++it){
        cout << *it << endl;
    }
    return 0;
}