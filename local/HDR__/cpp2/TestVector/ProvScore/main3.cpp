#include<algorithm> // sort
#include<iostream>   //cerr
#include<vector>
#include<string>
#include<fstream>  //in, out
#include<cstdlib> //exit

#include"student.h"
using namespace std;



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

	while(s.read(in)){
		s.sum();
		s.average();
		students.push_back(s);
	}

	::rank(students);

	//sorting
	sort(students.begin(), students.end());
	//sort(students.begin(), students.end()); // 구조체 타입에 크다 작다 가 없음 <-- 연산자로 정의 해주면 작동됨 
	 

	::print(out, students);


	return 0;
}
