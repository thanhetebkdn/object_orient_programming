#include "Valid.h"
#include <regex>

bool isValidBirthday(const std::string &birthday)
{
    std::regex birthdayRegex(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(\d{4})$)");
    return std::regex_match(birthday, birthdayRegex);
}

bool isValidEmail(const std::string &email)
{
    std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, emailRegex);
}

bool isValidName(const std::string &name)
{
    std::regex nameRegex(R"(^[a-zA-ZÀ-ỹ\s]+$)");
    return !name.empty() && std::regex_match(name, nameRegex);
}

bool isValidPhone(const std::string &phone)
{
    std::regex phoneRegex(R"(^\d{10,15}$)");
    return std::regex_match(phone, phoneRegex);
}
