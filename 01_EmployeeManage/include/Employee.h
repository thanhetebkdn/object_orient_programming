#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
    Employee(std::string n, int a, std::string g, std::string addr);
    std::string getName();
    virtual void inputInfo();
    virtual void displayInfo();
    virtual ~Employee() = default;

private:
    std::string name;
    int age;
    std::string gender;
    std::string address;
};

#endif
