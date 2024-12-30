#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <iostream>
#include <string>
#include <Employee.h>

class Exprience : public Employee
{
public:
    Exprience();
    Exprience(int expInYear, int proSkill);
    void inputInfor() override;
    void showInfor() override;

private:
    int expInYear;
    int proSkill;
};

#endif