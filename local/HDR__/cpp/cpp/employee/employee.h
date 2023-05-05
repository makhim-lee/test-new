#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"

class Employee{
private:
    int id_;
    String name_;
    const Employee *pManager_;

    Employee(const Employee* rhs);
    Employee& operator=(const Employee& rhs);
public:
    // Employee(); {}
    // ~Employee();  
    // xx    Employee(const Employee& rhs){memberwise copy}
    // xx    Employee& operator=(const Employee& rhs){memberwise copy return *this}
    // Employee *operator&() {return this;}
    // const Employee *operator&() const {return this;}

    Employee(int id, String name, const Employee *pManager);
    int getId() const;
    String getName() const;
    const Employee *getManager() const;

    bool isManager() const;
    // void setName()  <-- sql에서 접근
    void setManager(const Employee *pManager);

};

#endif