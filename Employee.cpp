//
// Created by seoyeon on 2021-05-26.
//

#include "Employee.h"

Employee::Employee(const string &name, const string &company, Level level) : Person(name) ,companyName(company), employeeLevel(level){}

void Employee::changeEmployeeInfo(const string &companyName, Level level) {
    Employee::companyName = companyName;
    employeeLevel.setLevel(level);
}

bool Employee::isEmployee(const string &name) {
    return (this->getName() == name);
}


ostream &operator<<(ostream &os, const Employee& employee) {
    os << employee.employeeLevel.getLabel() << " " << employee.getName() << " works for " << employee.companyName <<endl;
    return os;
}

///////////////////////////////////////////////////////////////////////////////////////

ManagerWithDefaultPointer::ManagerWithDefaultPointer(const string &name, const string &companyName, Level level)
        : Employee(name, companyName, level) {}

void ManagerWithDefaultPointer::addEmployee(Employee *const pEmployee) {
    if (pEmployee == nullptr) {
        cout << "Failed: employee is empty!!" << endl;
    }else {
        group.push_back(pEmployee);
    }
}

size_t ManagerWithDefaultPointer::getEmployeeNumber() {
    return group.size();
}

ostream &operator<<(ostream &os, const ManagerWithDefaultPointer &manager) {
    os << (Employee)manager;
    os << "List of employees managed by me" << endl;
    for (Employee* employee : manager.group)
        os << *employee;
    return os;
}

ManagerWithDefaultPointer::~ManagerWithDefaultPointer() {
    for(int i=0;i<group.size();++i){
        delete group[i];
    }
    group.clear();
}

void ManagerWithDefaultPointer::changeEmployee(const string &name, const string &companyName, Level level) {
    for(auto i=group.begin();i!=group.end();++i){
        if((*i)->isEmployee(name)){
            (*i)->changeEmployeeInfo(companyName, level);
            (*i)->rename(name);
        }
    }
}

void ManagerWithDefaultPointer::deleteEmployee(const string &name) {
    for(auto i=group.begin();i!=group.end();++i){
        if((*i)->isEmployee(name)) group.erase(i);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ManagerWithSmartPointer::ManagerWithSmartPointer(const string &name, const string &companyName, Level level)
    : Employee(name, companyName, level) {}

void ManagerWithSmartPointer::addEmployee(unique_ptr<Employee> &employee) {
    if (employee == nullptr) {
        cout << "Failed: employee is empty!!" << endl;
    }else {
        employees.push_back(std::move(employee));
    }

}

size_t ManagerWithSmartPointer::getEmployeeNumber() {
    return employees.size();
}

ostream &operator<<(ostream &os, const ManagerWithSmartPointer &manager) {
    os << static_cast<Employee>(manager);
    os << "List of employees managed by me" << endl;
    for (auto i = manager.employees.begin(); i < manager.employees.end(); ++i) {
        os << *(*i);
    }
    return os;
}

void ManagerWithSmartPointer::changeEmployee(const string &name, const string &companyName, Level level) {
    for(auto i=employees.begin();i!=employees.end();++i){
        if((*i)->isEmployee(name)) {
            (*i)->changeEmployeeInfo(companyName,level);
            (*i)->rename(name);
        }
    }
}

void ManagerWithSmartPointer::deleteEmployee(const string &name) {
    for(auto i=employees.begin();i!=employees.end();++i){
        if((*i)->isEmployee(name)) employees.erase(i);
    }
}
