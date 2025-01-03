#include <iostream>
#include "Employee.h"

Employee::Employee(std::string n, int a, std::string g, std::string addr)
    : name(n), age(a), gender(g), address(addr) {}

std::string Employee::getName()
{
    return name;
}

void Employee::inputInfo()
{
    std::cout << "Enter employee name: ";
    std::cin >> name;

    std::cout << "Enter employee age: ";
    std::cin >> age;

    std::cout << "Enter employee gender: ";
    std::cin >> gender;

    std::cout << "Enter employee address: ";
    std::cin >> address;
}

void Employee::displayInfo()
{
    std::cout << "Employee name: " << name << std::endl;
    std::cout << "Employee age: " << age << std::endl;
    std::cout << "Employee gender: " << gender << std::endl;
    std::cout << "Employee address: " << address << std::endl;
}
