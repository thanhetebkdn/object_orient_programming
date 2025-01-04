#include "Fresher.h"

Fresher::Fresher() : graduationDate(""),
                     graduationRank(""), education("") {}
Fresher::Fresher(std::string graduationDate, std::string graduationRank,
                 std::string education) : graduationDate(graduationDate),
                                          graduationRank(graduationRank), education(education) {}

void Fresher::inputInfor()
{
    Employee::inputInfor();

    do
    {
        std::cout << "Enter your Graduation Date (dd/mm/yyyy): ";
        std::cin >> graduationDate;
        try
        {
            isValidGraduationDate(graduationDate);
            break;
        }
        catch (const GraduationDateException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);

    do
    {
        std::cout << "Enter your Graduation Rank: ";
        std::cin >> graduationRank;
        try
        {
            isValidGraduationRank(graduationRank);
            break;
        }
        catch (const GraduationRankException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);

    do
    {
        std::cout << "Enter your Education: ";
        std::cin >> education;
        try
        {
            isValidEducation(education);
            break;
        }
        catch (const EducationException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);
}

void Fresher::showInfor()
{
    Employee::showInfor();
    std::cout << "Your Graduation Date: " << graduationDate << std::endl;
    std::cout << "Your Graduation Rank : " << graduationRank << std::endl;
    std::cout << "Your Education : " << education << std::endl;
}