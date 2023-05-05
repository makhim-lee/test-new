#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;   
int main()
{   
    cout << "input your name : ";
    string name;
    cin >> name;

    int pads;
    cout << "input null space : ";
    cin >> pads;
    const string greeting = "Hello, " + name + "!";

    const int row = 3 + 2 * pads;
    //const int col = greeting.size() + 2 + 2 * pads;
    const string::size_type col = greeting.size()  + 2 + 2 * pads; 
    // 라이브러리에안에 class는 보통 size_type 로 재정의 해서 씀 !!!  
    
    // '*' / ' ' / 'sting'
    for (int i = 0; i < row; ++i){
        for(int k = 0; k < col; ++k){
            if(i == 0 || i == (row-1) || k == 0 || k == (col-1)){
                cout << "*";
            }else if (i == row / 2 && k == (pads+1)/*(k > pads && k < col - (1+pads))*/){
                //cout << greeting[k - (1+pads)];
                cout << greeting;
                k += greeting.size() - 1;
            }else cout << " ";
        }
        cout << endl;
    }
    return 0;
}