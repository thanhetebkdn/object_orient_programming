#ifndef EMPLOYEEMANAGE_H
#define EMPLOYEEMANAGE_H
#include <iostream>
#include <vector>
#include <memory>
#include "Employee.h"
class EmployeeManage
{
public:
    void addNewEmployee();
    void modifyID();
    void deleteByID();
    void showAllEmployee();
    void exitProgram();

private:
    std::vector<std::unique_ptr<Employee>> listEmployee;
};

#endif