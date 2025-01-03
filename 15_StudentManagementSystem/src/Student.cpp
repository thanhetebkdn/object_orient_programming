#include <limits>
#include <regex>
#include "Student.h"
#include "AcademicResult.h"
#include "Exception.h"
#include "Validation.h"

Student::Student()
    : student_id(""), full_name(""), dateBirthday(""), entry_score(0.0), enrollment_year(0) {}

Student::Student(std::string student_id, std::string full_name, std::string dob,
                 float entry_score, int enrollment_year)
    : student_id(student_id), full_name(full_name), dateBirthday(dob),
      entry_score(entry_score), enrollment_year(enrollment_year) {}
void Student::inputInfor()
{

    while (true)
    {
        std::cout << "Enter student ID: ";
        std::getline(std::cin, student_id);
        try
        {
            isValidStudentID(student_id);
            break;
        }
        catch (const InvalidStudentIDException &e)
        {
            std::cout << e.what() << " Please try again.\n";
        }
    }

    while (true)
    {
        std::cout << "Enter full name: ";
        std::getline(std::cin, full_name);
        try
        {
            isValidName(full_name);
            break;
        }
        catch (const InvalidFullNameException &e)
        {
            std::cout << e.what() << " Please try again.\n";
        }
    }

    while (true)
    {
        std::cout << "Enter birth date (DD/MM/YYYY): ";
        std::getline(std::cin, dateBirthday);
        try
        {
            isValidDate(dateBirthday);
            break;
        }
        catch (const InvalidDOBException &e)
        {
            std::cout << e.what() << " Please try again.\n";
        }
    }

    while (true)
    {
        std::cout << "Enter entry score: ";
        std::cin >> entry_score;
        try
        {
            isValidScore(entry_score);
            break;
        }
        catch (const InvalidScoreException &e)
        {
            std::cout << e.what() << " Please try again.\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    while (true)
    {
        std::cout << "Enter enrollment year: ";
        std::cin >> enrollment_year;
        try
        {
            isValidEnrollmentYear(enrollment_year);
            break;
        }
        catch (const InvalidEnrollmentYearException &e)
        {
            std::cout << e.what() << " Please try again.\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    int num_results;
    while (true)
    {
        std::cout << "Enter number of academic results: ";
        std::cin >> num_results;
        try
        {
            isValidNumberOfStudents(num_results);
            break;
        }
        catch (const InvalidNumberOfStudentsException &e)
        {
            std::cout << e.what() << " Please try again.\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    academic_results.resize(num_results);
    for (int i = 0; i < num_results; ++i)
    {
        std::cout << "Enter result for semester " << i + 1 << ":\n";
        academic_results[i] = std::make_shared<AcademicResult>();
        academic_results[i]->inputResult();
    }
}

void Student::outputInfor()
{
    std::cout << "Student ID: " << student_id << "\n";
    std::cout << "Full Name: " << full_name << "\n";
    std::cout << "Birth Date: " << dateBirthday << "\n";
    std::cout << "Entry Score: " << entry_score << "\n";
    std::cout << "Enrollment Year: " << enrollment_year << "\n";
    std::cout << "Academic Results: \n";
    for (const auto &result : academic_results)
    {
        result->outputResult();
    }
}

bool Student::isFullTime()
{
    if (entry_score >= 5.0)
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        int current_year = now->tm_year + 1900;

        if (enrollment_year <= current_year)
        {
            return true;
        }
    }
    return false;
}

float Student::getEntryScore()
{
    return entry_score;
}

std::vector<std::shared_ptr<AcademicResult>> &Student::getAcademicResults()
{
    return academic_results;
}

int Student::getEnrollmentYear() const
{
    return enrollment_year;
}