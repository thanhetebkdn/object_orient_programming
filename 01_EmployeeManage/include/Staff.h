#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"

class Staff : public Employee
{
public:
    Staff();
    Staff(const std::string &n, int a, const std::string &g, const std::string &addr, const std::string &j);
    void inputInfo() override;
    void displayInfo() const override;

private:
    std::string job;
};

#endif
