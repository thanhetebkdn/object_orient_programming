#include <iomanip>
#include "AcademicResult.h"
#include "Exception.h"
#include "Validation.h"

void AcademicResult::inputResult()
{
    std::cout << "Enter semester name (e.g., Fall 2023): ";
    std::getline(std::cin, semester_name);

    try
    {
        isValidSemesterName(semester_name);
    }
    catch (const InvalidSemesterNameException &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }

    std::cout << "Enter GPA for " << semester_name << ": ";
    std::cin >> semester_gpa;
    std::cin.ignore();

    try
    {
        isValidGPA(semester_gpa);
    }
    catch (const InvalidGPAException &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
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
