#include <iostream>
#include "Employee.h"

int main() {
    auto e1 = make_unique<Employee>("Hong2", "GoodCompany");
    auto e2 = make_unique<Employee>("Kim2", "GoodCompany", ASSISTANT_MANAGER);
    auto e3 = make_unique<Employee>("Cha2", "GoodCompany", DEPUTY_GENERAL_MANAGER);
    cout << *e1 << *e2 << *e3;
    ManagerWithSmartPointer m("Tom2", "GoodCompany", GENERAL_MANAGER);
    m.addEmployee(e1);
    m.addEmployee(e2);
    m.addEmployee(e3);
    m.changeEmployee("shit","ShitCompany",ASSISTANT_MANAGER);
    cout << endl << "Information for Manager" << endl;
    cout << m.getEmployeeNumber() << endl;
    cout << m;
}
