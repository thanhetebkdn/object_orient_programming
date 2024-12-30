#include "Intern.h"

Intern::Intern() : major(""), semester(""), universityName("") {}
Intern::Intern(std::string major, std::string semester,
               std::string universityName)
    : major(major), semester(semester), universityName(universityName) {}

void Intern::inputInfor()
{
    Employee::inputInfor();
    std::cout << "Enter your Major: ";
    std::cin >> major;
    std::cout << "Enter your Semester: ";
    std::cin >> semester;
    std::cout << "Enter your University name: ";
    std::cin >> universityName;
}

void Intern::showInfor()
{
    Employee::showInfor();
    std::cout << "Your Major: " << major << std::endl;
    std::cout << "Your Semester: " << semester << std::endl;
    std::cout << "Your University Name: " << universityName << std::endl;
}