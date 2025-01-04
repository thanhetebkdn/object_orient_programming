#include "EmployeeManager.h"
#include "Worker.h"
#include "Engineer.h"
#include "Staff.h"
#include <iostream>
#include <limits>

void EmployeeManager::addNewEmployee()
{
    int employeeType;
    std::cout << "1. Worker - 2. Engineer - 3. Staff: ";
    std::cin >> employeeType;

    std::unique_ptr<Employee> employee;

    switch (employeeType)
    {
    case 1:
        employee = std::make_unique<Worker>();
        break;
    case 2:
        employee = std::make_unique<Engineer>();
        break;
    case 3:
        employee = std::make_unique<Staff>();
        break;
    default:
        std::cout << "Invalid choice\n";
        return;
    }

    employee->inputInfo();
    employeeList.push_back(std::move(employee));
}

void EmployeeManager::searchByName()
{
    std::string name;
    std::cin.ignore();
    std::cout << "Enter employee name to search: ";
    std::getline(std::cin, name);

    bool found = false;
    for (const auto &employee : employeeList)
    {
        if (employee->getName() == name)
        {
            employee->displayInfo();
            std::cout << "---------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No employee found with name: " << name << "\n";
    }
}

void EmployeeManager::displayAll()
{
    if (employeeList.empty())
    {
        std::cout << "No employees in the list.\n";
        return;
    }

    for (const auto &employee : employeeList)
    {
        employee->displayInfo();
        std::cout << "---------------------\n";
    }
}

void EmployeeManager::exitProgram()
{
    std::cout << "Exiting program...\n";
    exit(0);
}
