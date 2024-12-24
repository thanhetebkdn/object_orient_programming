#include "Staff.h"
#include <iostream>

Staff::Staff() : Employee("", 0, "", ""), job("") {}

Staff::Staff(std::string n, int a, std::string g, std::string addr, std::string j)
    : Employee(n, a, g, addr), job(j) {}

void Staff::inputInfo()
{
    Employee::inputInfo();
    std::cout << "Enter staff job: ";
    std::cin >> job;
}

void Staff::displayInfo()
{
    Employee::displayInfo();
    std::cout << "Staff job: " << job << std::endl;
}
