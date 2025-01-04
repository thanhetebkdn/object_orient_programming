#include <iostream>
#include <limits>
#include "Employee.h"

Employee::Employee(const std::string &n, int a, const std::string &g, const std::string &addr)
    : name(n), age(a), gender(g), address(addr) {}

std::string Employee::getName() const
{
    return name;
}

void Employee::inputInfo()
{
    std::cin.ignore();
    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);

    while (true)
    {
        std::cout << "Enter employee age: ";
        std::cin >> age;
        if (std::cin.fail() || age <= 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Age must be positive.\n";
        }
        else
        {
            break;
        }
    }

    std::cin.ignore();
    std::cout << "Enter employee gender: ";
    std::getline(std::cin, gender);

    std::cout << "Enter employee address: ";
    std::getline(std::cin, address);
}

void Employee::displayInfo() const
{
    std::cout << "Employee name: " << name << "\n"
              << "Employee age: " << age << "\n"
              << "Employee gender: " << gender << "\n"
              << "Employee address: " << address << "\n";
}
