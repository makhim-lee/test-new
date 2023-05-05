#ifndef STUDENT_H
#define STUDENT_H

#include<string>

using namespace std;


class Student;

ostream& print(ostream& out,const vector<Student>& students);

class Student{
friend ostream& operator<<(ostream& out, const Student& s);
friend void rank(vector<Student>& students);
private:
	string name_;
	int kor_;
	int eng_;
	int mat_;
	int sum_;
	double ave_;
	int rank_;

public:

    
    Student(istream& in);
    Student();
    istream& read(istream& in);
    void sum();
    void average();
    bool operator<(const Student&rhs)const;
    bool operator>(const Student&rhs)const;


};


#endif