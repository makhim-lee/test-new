#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<string> titles;
    vector<int> counts;
    string line;
    
    vector<string>::size_type i;
    while(cin){
        getline(cin, line);
        
        for ( i = 0; i < titles.size(); ++i){
            if(line == "\0")break;
        }
        if (i == titles.size()){
            titles.push_back(line);
            counts.push_back(line.size());
        }else ++counts[i];
    }
    int longer = 0;
    for(i = 0; i < counts.size(); ++i){
        if(longer < counts[i]) longer = counts[i];
    }

    int xLine = 4 + longer;
    int yLine = titles.size() + 1;

    cout<<xLine<<"   "<<yLine<<endl;

    for(int y = 0; y < yLine; ++y){
        for(int x = 0; x < xLine; ++x){
            if(y == 0 || y == (yLine-1) || x == 0 || x == (xLine-1)){
                cout<<"*";
            }else if(x <= (counts[y-1]+1)){
                cout<<titles[y-1];
                x += counts[y-1];
            }else cout<<" ";
        }
        cout<<endl;
    }
}


