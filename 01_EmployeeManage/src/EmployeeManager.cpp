#include <iostream>
#include <memory>
#include "EmployeeManager.h"
#include "Worker.h"
#include "Engineer.h"
#include "Staff.h"

void EmployeeManager::addNewEmployee()
{
    int employeeType;
    std::cout << "1. Worker - 2. Engineer - 3. Staff\n";
    std::cin >> employeeType;

    std::unique_ptr<Employee> employee = nullptr;

    if (employeeType == 1)
    {
        employee = std::make_unique<Worker>();
    }
    else if (employeeType == 2)
    {
        employee = std::make_unique<Engineer>();
    }
    else if (employeeType == 3)
    {
        employee = std::make_unique<Staff>();
    }
    else
    {
        std::cout << "Invalid input\n";
        return;
    }
    employee->inputInfo();
    employeeList.push_back(std::move(employee));
}

void EmployeeManager::searchByName()
{
    bool found = false;
    std::string employeeName;
    std::cout << "Enter employee name to search: \n";
    std::cin >> employeeName;

    for (auto &employee : employeeList)
    {
        if (employeeName == employee->getName())
        {
            employee->displayInfo();
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "No employee found with name: " << employeeName << std::endl;
    }
}

void EmployeeManager::displayAll()
{
    if (employeeList.empty())
    {
        std::cout << "Employee list is empty\n";
        return;
    }

    for (auto &employee : employeeList)
    {
        employee->displayInfo();
        std::cout << "---------------------" << std::endl;
    }
}

void EmployeeManager::exitProgram()
{
    std::cout << "Exiting program\n";
    exit(0);
}
