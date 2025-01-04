#ifndef ENGINEER_H
#define ENGINEER_H

#include "Employee.h"

class Engineer : public Employee
{
public:
    Engineer();
    Engineer(const std::string &n, int a, const std::string &g, const std::string &addr, const std::string &m);
    void inputInfo() override;
    void displayInfo() const override;

private:
    std::string major;
};

#endif
