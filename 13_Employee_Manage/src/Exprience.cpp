#include "Exprience.h"

Exprience ::Exprience() : expInYear(0), proSkill(0) {}
Exprience ::Exprience(int expInYear, int proSkill)
    : expInYear(expInYear), proSkill(proSkill) {}

void Exprience::inputInfor()
{
    Employee::inputInfor();
    std::cout << "Enter your Exprience Year: ";
    std::cin >> expInYear;
    std::cout << "Enter your Professional Skill: ";
    std::cin >> proSkill;
}

void Exprience::showInfor()
{
    Employee::showInfor();
    std::cout << "Your Exprience Year: " << expInYear << std::endl;
    std::cout << "Your Professional Skill : " << expInYear << std::endl;
}