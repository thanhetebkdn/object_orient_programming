#include "Engineer.h"
#include <iostream>

Engineer::Engineer() : Employee("", 0, "", ""), major("") {}

Engineer::Engineer(std::string n, int a, std::string g, std::string addr, std::string m)
    : Employee(n, a, g, addr), major(m) {}

void Engineer::inputInfo()
{
    Employee::inputInfo();
    std::cout << "Enter engineer major: ";
    std::cin >> major;
}

void Engineer::displayInfo()
{
    Employee::displayInfo();
    std::cout << "Engineer major: " << major << std::endl;
}
