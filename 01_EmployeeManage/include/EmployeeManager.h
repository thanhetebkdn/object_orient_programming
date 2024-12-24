#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "Employee.h"
#include <vector>
#include <memory>

class EmployeeManager
{
public:
    void addNewEmployee();
    void searchByName();
    void displayAll();
    void exitProgram();

private:
    std::vector<std::unique_ptr<Employee>> employeeList;
};

#endif // EMPLOYEEMANAGER_H
