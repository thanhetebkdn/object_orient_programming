#include "AcademicResult.h"
#include <iomanip>

void AcademicResult::inputResult()
{
    std::cout << "Enter semester name (e.g., Fall 2023): ";
    std::getline(std::cin, semester_name);

    std::cout << "Enter GPA for " << semester_name << ": ";
    std::cin >> semester_gpa;
    std::cin.ignore();
}

void AcademicResult::outputResult()
{
    std::cout << "Semester: " << semester_name << ", GPA: "
              << std::fixed << std::setprecision(2) << semester_gpa << std::endl;
}

std::string AcademicResult::getGPA()
{
    return std::to_string(semester_gpa);
}
