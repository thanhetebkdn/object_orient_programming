#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"

class Engineer : public Employee
{
public:
    Engineer();
    Engineer(std::string n, int a, std::string g, std::string addr, std::string m);
    void inputInfo() override;
    void displayInfo() override;

private:
    std::string major;
};

#endif
