#include<iomanip> //setw , setprecision
#include<iostream>
#include<vector>
#include"student.h"

using namespace std;

Student::Student(){

}

Student::Student(istream& in){


}



istream& Student::read(istream& in){
    in >> name_ >> kor_ >> eng_ >> mat_;
		 
    return in;
}

bool Student::operator<(const Student&rhs)const{
    return this->rank_ < rhs.rank_;
}
bool Student::operator>(const Student&rhs)const{
    return this->rank_ > rhs.rank_;
}


void Student::sum(){
    sum_ = kor_ + eng_ + mat_;
}

void Student::average(){
    ave_ = static_cast<double>(sum_)/3.0;
}

void rank(vector<Student>& students){
    for(auto it = students.begin(); it != students.end(); ++it){
        it->rank_ = 1 ; 
    }

    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it){
		for (vector<Student>::iterator it2 = students.begin(); it2 != students.end(); ++it2){
			if (it->sum_ < it2->sum_){
				++it->rank_;
			}
		} 
	}
}
ostream& print(ostream& out, const vector<Student>& students){
    out << "-------------------------------------------------------------"<<endl;

	for (vector<Student>::const_iterator it = students.cbegin(); it != students.cend(); ++it){
        out << *it <<endl;
        
	}
	out << "-------------------------------------------------------------"<<endl;
    return out;
}

ostream& operator<<(ostream& out, const Student& s){
    out << setw(20)<<s.name_<<setw(4)<<s.kor_;
    out << setw(4)<<s.eng_<<setw(4)<<s.mat_<<setw(4)<<s.sum_;
	out << setw(7)<<fixed<<setprecision(2)<< s.ave_<<setw(4)<<s.rank_;
}
