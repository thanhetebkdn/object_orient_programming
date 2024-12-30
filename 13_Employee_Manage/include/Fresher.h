#ifndef FRESHER_H
#define FRESHER_H
#include <iostream>
#include <string>
#include "Employee.h"

class Fresher : public Employee
{
public:
    Fresher();
    Fresher(std::string graduationDate, std::string graduationRank,
            std::string education);
    void inputInfor() override;
    void showInfor() override;

private:
    std::string graduationDate;
    std::string graduationRank;
    std::string education;
};

#endif