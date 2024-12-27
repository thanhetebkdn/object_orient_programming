#ifndef STAFF_H
#define STAFF_H

#include "Employee.h"

class Staff : public Employee
{
public:
    Staff();
    Staff(std::string n, int a, std::string g, std::string addr, std::string j);
    void inputInfo() override;
    void displayInfo() override;

private:
    std::string job;    
};

#endif // STAFF_H
