#include "Exprience.h"
#include "Valid.h"
#include <iostream>

Exprience::Exprience() : expInYear(0), proSkill(0) {}
Exprience::Exprience(int expInYear, int proSkill)
    : expInYear(expInYear), proSkill(proSkill) {}

void Exprience::inputInfor()
{
    Employee::inputInfor();

    while (true)
    {
        try
        {
            std::cout << "Enter your Experience Year: ";
            std::cin >> expInYear;

            if (std::cin.fail())
            {
                throw ExperienceYearException();
            }

            isValidExperienceYear(expInYear);
            break;
        }
        catch (const ExperienceYearException &e)
        {
            std::cerr << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }

    while (true)
    {
        try
        {
            std::cout << "Enter your Professional Skill: ";
            std::cin >> proSkill;

            if (std::cin.fail())
            {
                throw ProfessionalSkillException();
            }

            isValidProfessionalSkill(proSkill);
            break;
        }
        catch (const ProfessionalSkillException &e)
        {
            std::cerr << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }
}

void Exprience::showInfor()
{
    Employee::showInfor();
    std::cout << "Your Experience Year: " << expInYear << std::endl;
    std::cout << "Your Professional Skill: " << proSkill << std::endl;
}
