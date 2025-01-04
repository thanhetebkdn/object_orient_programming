#include "Validation.h"
#include <iostream>
#include <regex>
#include <stdexcept>
#include "Exception.h"

bool isValidFullName(const std::string &fullName)
{
    std::regex nameRegex(R"(^[a-zA-ZÀ-ỹ\s]+$)");
    if (fullName.empty() || !std::regex_match(fullName, nameRegex))
    {
        throw InvalidFullNameException();
    }
    return true;
}

bool isValidBirthday(const std::string &birthday)
{
    std::regex dobPattern(R"(\d{2}/\d{2}/\d{4})");
    if (!std::regex_match(birthday, dobPattern))
    {
        throw InvalidDOBException();
    }
    return true;
}

bool isValidPhoneNumber(const std::string &phone)
{
    std::regex phonePattern(R"(^(090|098|091|031|035|038)\d{7}$)");
    if (!std::regex_match(phone, phonePattern))
    {
        throw InvalidPhoneNumberException();
    }
    return true;
}

bool isValidStudentType(int choice)
{
    if (choice != 1 && choice != 2)
    {
        throw InvalidStudentTypeException();
    }
    return true;
}

bool isValidUniversityName(const std::string &universityName)
{
    if (universityName.empty())
    {
        throw InvalidUniversityNameException();
    }
    return true;
}

bool isValidGradeLevel(const std::string &gradeLevel)
{
    if (gradeLevel.empty())
    {
        throw InvalidGradeLevelException();
    }
    return true;
}

bool isValidGPA(float gpa)
{
    if (gpa < 0.0f || gpa > 10.0f)
    {
        throw InvalidGPAException();
    }
    return true;
}

bool isValidBestRewardName(const std::string &bestRewardName)
{
    if (bestRewardName.empty())
    {
        throw InvalidBestRewardNameException();
    }
    return true;
}

bool isValidEnglishScore(int englishScore)
{
    if (englishScore < 0 || englishScore > 990)
    {
        throw InvalidEnglishScoreException();
    }
    return true;
}

bool isValidEntryTestScore(int entryTestScore)
{
    if (entryTestScore < 0 || entryTestScore > 100)
    {
        throw InvalidEntryTestScoreException();
    }
    return true;
}
