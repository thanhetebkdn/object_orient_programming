#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Certificate.h"
#include "EmployeeType.h"

class Employee
{
public:
    Employee() = default;
    Employee(int id, std::string fullName, std::string email,
             std::string phone, std::string birthday);

    virtual void inputInfor();
    virtual void showInfor();
    void addCertificate(std::unique_ptr<Certificate>);
    static int getEmployeeCount();

    void setId(int id) { this->id = id; }
    int getId() { return id; }

private:
    int id;
    std::string fullName;
    std::string email;
    std::string phone;
    std::string birthday;
    static int employeeCount;
    EmployeeType employeeType;
    std::vector<std::unique_ptr<Certificate>> certificates;
};

#endif