#include<algorithm> // sort
#include<iostream>   //cerr
#include<vector>
#include<string>
#include<fstream>  //in, out
#include<cstdlib> //exit
#include<iomanip> //setw , setprecision
#include"student.h"
using namespace std;

class Student{
public:
	string name;
	int kor;
	int eng;
	int mat;
	int sum;
	double ave;
	int rank;
    vector<Student> students;
}

bool compare(const Student& s1, const Student& s2){
    return s1.sum > s2.sum;
}

int main()
{
    ifstream in("score.dat");
    ofstream out("score.out");

    if(!in.is_open() || !out.is_open()){
        cerr<<"cant open file"<<endl;
        exit(1);
    }

    vector<Student> students;
	Student s;
	do{
		in >> s.name >> s.kor >> s.eng >> s.mat;
		 
		s.sum = s.kor + s.eng + s.mat;
		s.ave = (double)s.sum / 3.0;
		s.rank = 1;
        students.push_back(s);
	}while(in);
	//rank
    
	for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it){
		for (vector<Student>::iterator it2 = students.begin(); it2 != students.end(); ++it2){
			if (it->sum < it2->sum){
				++it->rank;
			}
		} 
	}
    

	//sorting

	//sort(students.begin(), students.end()); // 구조체 타입에 크다 작다 가 없음 <-- 연산자로 정의 해주면 작동됨 

    out << "-------------------------------------------------------------"<<endl;
	sort(students.begin(), students.end(), compare);

	for (vector<Student>::const_iterator it = students.cbegin(); it != students.cend(); ++it){
        out << setw(20)<<it->name<<setw(4)<<it->kor;
        out << setw(4)<<it->eng<<setw(4)<<it->mat<<setw(4)<<it->sum;
		out << setw(7)<<fixed<<setprecision(2)<< it->ave<<setw(4)<<it->rank<<endl;
	}
	out << "-------------------------------------------------------------"<<endl;
	return 0;
}
