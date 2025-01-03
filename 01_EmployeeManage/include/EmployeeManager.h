#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <vector>
#include <memory>
#include "Employee.h"

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

#endif
