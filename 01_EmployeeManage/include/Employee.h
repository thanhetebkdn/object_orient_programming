#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
    Employee(const std::string &n, int a, const std::string &g, const std::string &addr);
    virtual ~Employee() = default;
    virtual void inputInfo();
    virtual void displayInfo() const;
    std::string getName() const;

protected:
    std::string name;
    int age;
    std::string gender;
    std::string address;
};

#endif
