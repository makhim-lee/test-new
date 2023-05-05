#include<iostream>
#include"employee.h"

void printEmployee(const Employee *p){  // 객체를 heap상에 생성
    std::cout << p->getId() << ", " << p->getName()<<", ";
    if(p->isManager()){
        std::cout<<"Manager";
    }else{
        std::cout<<p->getManager()->getName();
    }
    std::cout << std::endl;
}

int main()
{
    Employee e1(1, "Park Jung Seok", NULL);
    //Employee e2;   
    //Employee e3 = e1;
    //e1 = e2;

    Employee *employees[5];
    employees[0] = new Employee(1, "Park Jung Seok", NULL);
    employees[1] = new Employee(2, "Sung Young HO", employees[0]);
    employees[2] = new Employee(3, "Sim Sung Suk", employees[0]);
    employees[3] = new Employee(4, "Choi Su", employees[2]);
    employees[4] = new Employee(5, "Kim Young", employees[1]);

    
    for(int i = 0; i < 5; ++i){
        printEmployee(employees[i]);
    }

    for(int i = 0; i < 5; ++i){
        delete employees[i];
    }

    return 0;    
}