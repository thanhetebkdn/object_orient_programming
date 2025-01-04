#include "Worker.h"
#include <iostream>

Worker::Worker() : Employee("", 0, "", ""), level(0) {}

Worker::Worker(const std::string &n, int a, const std::string &g, const std::string &addr, int lvl)
    : Employee(n, a, g, addr), level(lvl) {}

void Worker::inputInfo()
{
    Employee::inputInfo();
    std::cout << "Enter worker level: ";
    std::cin >> level;
}

void Worker::displayInfo() const
{
    Employee::displayInfo();
    std::cout << "Worker level: " << level << "\n";
}
