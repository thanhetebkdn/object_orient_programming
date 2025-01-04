#include "Staff.h"
#include <iostream>

Staff::Staff() : Employee("", 0, "", ""), job("") {}

Staff::Staff(const std::string &n, int a, const std::string &g, const std::string &addr, const std::string &j)
    : Employee(n, a, g, addr), job(j) {}

void Staff::inputInfo()
{
    Employee::inputInfo();
    std::cout << "Enter staff job: ";
    std::getline(std::cin, job);
}

void Staff::displayInfo() const
{
    Employee::displayInfo();
    std::cout << "Staff job: " << job << "\n";
}
