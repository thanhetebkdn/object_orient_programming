#include "Fresher.h"

Fresher::Fresher() : graduationDate(""),
                     graduationRank(""), education("") {}
Fresher::Fresher(std::string graduationDate, std::string graduationRank,
                 std::string education) : graduationDate(graduationDate),
                                          graduationRank(graduationRank), education(education) {}

void Fresher::inputInfor()
{
    Employee::inputInfor();
    std::cout << "Enter your Graduation Date: ";
    std::cin >> graduationDate;
    std::cout << "Enter your Graduation Rank: ";
    std::cin >> graduationRank;
    std::cout << "Enter your Education: ";
    std::cin >> education;
}

void Fresher::showInfor()
{
    Employee::showInfor();
    std::cout << "Your Graduation Date: " << graduationDate << std::endl;
    std::cout << "Your Graduation Rank : " << graduationRank << std::endl;
    std::cout << "Your Education : " << education << std::endl;
}