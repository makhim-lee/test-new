#include<iostream>
#include<ostream>

using std::cin;
using std::cout;
using std::endl;

class Mas{
friend std::ostream& operator<<(std::ostream& out, const Mas& rhs);
private:
    int** m_arr;
    int m_x;
    int m_y;
    int m_save;
    int m_chk;
public:
    Mas(int x);
    ~Mas();
    int getX();
    int getY();
    void setMas();
    void findPoint(const int x, const char point);
    void chkChk(const char point);
};

int main(){
    Mas m1(3);
    m1.setMas();
    
    for(int i = 1; i < 3; ++i){
        m1.findPoint(i, 'x');
    }
    m1.chkChk('x');
    for(int i = 1; i < 3; ++i){
        m1.findPoint(i, 'y');
    }
    m1.chkChk('y');
    cout<<m1<<endl;

    return 0;
}

std::ostream& operator<<(std::ostream& out, const Mas& rhs){
    return out<<rhs.m_x<<" "<<rhs.m_y;
}
Mas::Mas(int x)
:m_save(x), m_x(0), m_y(0), m_chk(1)
{
    m_arr = new int*[x]; 
    for(int i = 0; i < x; ++i) {
        m_arr[i] = new int[2];
        for (int j = 0; j < 2; j++) m_arr[i][j] = 0;           
    }
}
Mas::~Mas(){
    for (int i = 0; i < m_save; i++) {
        delete[] m_arr[i];
    }
    delete[] m_arr;
}

int Mas::getX(){
    return m_x;
}
int Mas::getY(){
    return m_y;
}

void Mas::setMas(){
    for(int i = 0; i < m_save; ++i){
        cin>>m_arr[i][0]>>m_arr[i][1];
    }
}
void Mas::findPoint(const int i, const char point){
    if(m_arr[0][point - 120] == m_arr[i][point - 120] && point == 120){
        if(i == 2)      m_x = m_arr[1][point - 120];
        else if(i == 1) m_x = m_arr[2][point - 120];
    }else if(m_arr[0][point - 120] == m_arr[i][point - 120] && point == 121) {
        if(i == 2)      m_y = m_arr[1][point - 120];
        else if(i == 1) m_y = m_arr[2][point - 120];
    }
    m_chk = 0;
}   

void Mas::chkChk(const char point){
    if(point == 120){
        if (m_chk) m_x = m_arr[0][0];
        else m_chk = 1;
    }else if(point == 121){
        if (m_chk) m_y = m_arr[0][0];
        else m_chk = 1;
    }
}