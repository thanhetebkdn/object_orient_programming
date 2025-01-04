#include "Validation.h"
#include <regex>
#include <cctype>
#include <stdexcept>

bool isValidEmail(const std::string &email)
{
    std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!std::regex_match(email, emailRegex))
    {
        throw InvalidEmailException();
    }
    return true;
}

bool isValidName(const std::string &name)
{
    std::regex nameRegex(R"(^[a-zA-ZÀ-ỹ\s]+$)");
    if (name.empty() || !std::regex_match(name, nameRegex))
    {
        throw InvalidFullNameException();
    }
    return true;
}

bool isValidPhone(const std::string &phone)
{
    std::regex phoneRegex(R"(^0\d{9,14}$)");
    if (!std::regex_match(phone, phoneRegex))
    {
        throw InvalidPhoneException();
    }
    return true;
}

bool isValidStudentID(const std::string &student_id)
{
    std::regex idRegex(R"(^[A-Za-z0-9]{1,5}$)");
    if (!std::regex_match(student_id, idRegex))
    {
        throw InvalidStudentIDException();
    }
    return true;
}

bool isValidDate(const std::string &date)
{
    std::regex dateRegex(R"(^\d{2}/\d{2}/\d{4}$)");
    if (!std::regex_match(date, dateRegex))
    {
        throw InvalidDOBException();
    }

    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);

    if (month < 1 || month > 12 || day < 1 || day > 31)
        throw InvalidDOBException();

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        throw InvalidDOBException();

    return true;
}

bool isValidScore(double score)
{
    if (score < 0.0 || score > 10.0)
    {
        throw InvalidScoreException();
    }
    return true;
}

bool isValidTrainingLocation(const std::string &location)
{
    if (location.length() < 5 || location.length() > 100)
    {
        throw InvalidTrainingLocationException();
    }
    for (char c : location)
    {
        if (!std::isalnum(c) && c != ' ' && c != ',' && c != '.' && c != '-')
        {
            throw InvalidTrainingLocationException();
        }
    }
    return true;
}

bool isValidFacultyName(const std::string &name)
{
    if (name.length() < 5 || name.length() > 100)
    {
        throw InvalidFacultyNameException();
    }
    for (char c : name)
    {
        if (!std::isalnum(c) && c != ' ' && c != ',' && c != '.' && c != '-')
        {
            throw InvalidFacultyNameException();
        }
    }
    return true;
}

bool isValidNumberOfStudents(int num_students)
{
    if (num_students <= 0)
    {
        throw InvalidNumberOfStudentsException();
    }
    return true;
}

bool isValidEnrollmentYear(int year)
{
    int currentYear = 2025;
    if (year < 2000 || year > currentYear)
    {
        throw InvalidEnrollmentYearException();
    }
    return true;
}

bool isValidSemesterName(const std::string &semester_name)
{
    std::regex semesterNameRegex(R"(^[A-Za-z0-9\s]+$)");
    if (!std::regex_match(semester_name, semesterNameRegex))
    {
        throw InvalidSemesterNameException();
    }
    return true;
}

bool isValidGPA(double gpa)
{
    if (gpa < 0.0 || gpa > 10.0)
    {
        throw InvalidGPAException();
    }
    return true;
}
