#include "Validation.h"
#include <iostream>
#include <regex>
#include <stdexcept>
#include "Exception.h"

bool isValidFullName(const std::string &fullName)
{
    if (fullName.length() < 10 || fullName.length() > 50)
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
