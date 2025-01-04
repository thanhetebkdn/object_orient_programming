#include "Engineer.h"
#include <iostream>

Engineer::Engineer() : Employee("", 0, "", ""), major("") {}

Engineer::Engineer(const std::string &n, int a, const std::string &g, const std::string &addr, const std::string &m)
    : Employee(n, a, g, addr), major(m) {}

void Engineer::inputInfo()
{
    Employee::inputInfo();
    std::cout << "Enter engineer major: ";
    std::getline(std::cin, major);
}

void Engineer::displayInfo() const
{
    Employee::displayInfo();
    std::cout << "Engineer major: " << major << "\n";
}
