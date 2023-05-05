#include "employee.h"

Employee::Employee(int id, String name, const Employee *pManager)
: id_(id), name_(name), pManager_(pManager)
{}

int Employee::getId() const{
    return id_;
}

String Employee::getName() const{
     return name_;
}

const Employee *Employee::getManager() const{
    return pManager_;
}

bool Employee::isManager() const{
    return pManager_ == NULL;
}

void Employee::setManager(const Employee *pManager){
    pManager_ = pManager;
}
