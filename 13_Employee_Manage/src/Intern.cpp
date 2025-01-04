#include "Intern.h"
#include "Valid.h"
#include "Exception.h"

Intern::Intern() : major(""), semester(""), universityName("") {}
Intern::Intern(std::string major, std::string semester,
               std::string universityName)
    : major(major), semester(semester), universityName(universityName) {}

void Intern::inputInfor()
{
    Employee::inputInfor();

    do
    {
        std::cout << "Enter your Major: ";
        std::cin >> major;
        try
        {
            isValidMajor(major);
            break;
        }
        catch (const MajorException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);

    do
    {
        std::cout << "Enter your Semester: ";
        std::cin >> semester;

        try
        {

            int semesterInt = std::stoi(semester);
            isValidSemester(semesterInt);
            break;
        }
        catch (const SemesterException &e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch (const std::invalid_argument &)
        {
            std::cerr << "Invalid input for semester. Please enter an integer." << std::endl;
        }
        catch (const std::out_of_range &)
        {
            std::cerr << "Semester is out of range. Please enter a valid semester." << std::endl;
        }
    } while (true);

    do
    {
        std::cout << "Enter your University name: ";
        std::cin >> universityName;
        try
        {
            isValidUniversityName(universityName);
            break;
        }
        catch (const UniversityNameException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);
}

void Intern::showInfor()
{
    Employee::showInfor();
    std::cout << "Your Major: " << major << std::endl;
    std::cout << "Your Semester: " << semester << std::endl;
    std::cout << "Your University Name: " << universityName << std::endl;
}