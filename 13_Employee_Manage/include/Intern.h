#ifndef INTERN_H
#define INTERN_H

#include <Employee.h>
#include <iostream>
#include <string>

class Intern : public Employee
{
public:
    Intern();
    Intern(std::string major, std::string semester,
           std::string universityName);
    void inputInfor() override;
    void showInfor() override;

private:
    std::string major;
    std::string semester;
    std::string universityName;
};

#endif