//
// Created by seoyeon on 2021-05-26.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

enum Level { STAFF, ASSISTANT_MANAGER, MANAGER, DEPUTY_GENERAL_MANAGER, GENERAL_MANAGER };

class EmployeeLevel {
private:
    Level level;

public:
    explicit EmployeeLevel(Level level = STAFF) : level(level) { }
    const string& getLabel() const {
        static string labels[] = { "S", "AM", "M", "DGM", "GM" };
        return labels[level];
    }
    void setLevel(Level level) { this->level = level; }
};

class Person {
    string name ;
    int age ;
    string address ;
public:
    Person(const string& theName,
           int theAge=1, const string& theAddress="")
            : name(theName), address(theAddress) {
        this->age = theAge ;
    };
    string getName() const {return name;};
    void rename(const string& theName) {name = theName;};
    int getAge() const {return age;};
    void increaseAge() {age=age+1;};
    string getAddress() const {return address;};
    void moveTo(const string& theAddress) {address=theAddress;};
};

class Employee : public Person {
private:
    string companyName;
    EmployeeLevel employeeLevel;

public:
    Employee(const string& name, const string& company, Level level = STAFF);

    void changeEmployeeInfo(const string& companyName, Level level);
    bool isEmployee(const string& name);

    friend ostream& operator<<(ostream& os, const Employee& employee);
};

class ManagerWithDefaultPointer : public Employee {
private:
    vector<Employee*> group;

public:
    ManagerWithDefaultPointer(const string &name, const string &companyName, Level level);
    ~ManagerWithDefaultPointer();

    void addEmployee(Employee* const pEmployee);
    void changeEmployee(const string& name, const string& companyName, Level level);
    void deleteEmployee(const string& name);
    size_t getEmployeeNumber();

    friend ostream& operator<<(ostream& os, const ManagerWithDefaultPointer& manager);
};

class ManagerWithSmartPointer : public Employee {
private:
    vector<unique_ptr<Employee>> employees;

public:
    ManagerWithSmartPointer(const string &name, const string &companyName, Level level);

    void addEmployee(unique_ptr<Employee>& employee);
    void changeEmployee(const string& name, const string& companyName, Level level);
    void deleteEmployee(const string& name);
    size_t getEmployeeNumber();

    friend ostream& operator<<(ostream& os, const ManagerWithSmartPointer& manager);
};

#endif //EMPLOYEE_EMPLOYEE_H
