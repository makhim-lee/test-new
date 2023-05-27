#include <iostream>
using namespace std;

class Chess{
friend istream& operator>>(istream& input, Chess& rhs);
friend ostream& operator<<(ostream& out, const Chess& rhs);
private:
    char** board;
    int x_, y_;
public:
    Chess(int x = 0, int y = 0);
    ~Chess();
    void ChessPrint();
    //void chackChess();
};

int main()
{
    int x, y;
    cin>>x>>y;
    Chess c1(x, y);
    cin>>c1;
    //c1.ChessPrint();
    cout<<c1<<endl;

    return 0;
}

istream& operator>>(istream& input, Chess& rhs){
    for (int i = 0; i < rhs.y_; ++i) {
        for (int j = 0; j < rhs.x_; ++j) {
            input >> rhs.board[i][j];
        }
    }
    return input;
}
ostream& operator<<(ostream& out, const Chess& rhs){
    for (int k = 0; k <= (rhs.y_ - 8); ++k){
        for (int t = 0; t < (rhs.x_ - 8); ++t){
            for (int i = k; i < k + 8; ++i){
                for (int j = t; j < t + 7; ++j){
                    rhs.board[i][j] = (rhs.board[i][j] == rhs.board[i][j+1])? 1 : 0;
                }
            }
     
        }
    }

    return out<<best;
}

Chess::Chess(int x, int y)
:x_(x), y_(y){   
    board = new char*[y_];
    for (int i = 0; i < y_; ++i){
        board[i] = new char[x_];
    }
}

Chess::~Chess(){
    for(int i = 0; i > y_; ++i){
        delete [] board[i];
    }
}

void Chess::ChessPrint(){
    for (int i = 0; i < y_; ++i) {
        for (int j = 0; j < x_; ++j) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

//backup
// char chack;//B 66 W 87
//     int countB, countW, best = 99;
    // for (int k = 0; k <= (rhs.y_ - 8); ++k){
    //     for (int t = 0; t <= (rhs.x_ - 8); ++t){
//             countB = 0; countW = 0;

//             for (int i = k; i < k + 8; ++i) {  //BW
//                 if((i - k) % 2 == 0) chack = 66;
//                 else if((i - k) % 2 == 1) chack = 87;

//                 for (int j = t; j < t + 8; ++j) {
//                     if(rhs.board[i][j] != chack) ++countB;
//                     if(chack == 66) chack = 87;
//                     else if(chack == 87) chack = 66;
//                 }
//             }
//             for (int i = k; i < k + 8; ++i) {  //BW
//                 if((i - k) % 2 == 0) chack = 87;
//                 else if((i - k) % 2 == 1) chack = 66;

//                 for (int j = t; j < t + 8; ++j) {
//                     if(rhs.board[i][j] != chack) ++countW;
//                     if(chack == 66) chack = 87;
//                     else if(chack == 87) chack = 66;
//                 }
//             }
//             cout<<countB<<" "<<countW<<endl;
//             if(countB > countW && best > countW) best = countW;
//             else if(countB < countW && best > countB) best = countB;

//             // if(best >= ((countB > countW)? countW : countB)){
//             //     best = (countB > countW)? countW : countB;
//             // }
//         }
//     }