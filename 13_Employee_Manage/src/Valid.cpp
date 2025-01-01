#include "Valid.h"
#include <regex>

bool isValidBirthday(const std::string &birthday)
{
    std::regex birthdayRegex(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(\d{4})$)");
    if (!std::regex_match(birthday, birthdayRegex))
    {
        throw BirthdayException();
    }
    return true;
}

bool isValidEmail(const std::string &email)
{
    std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!std::regex_match(email, emailRegex))
    {
        throw EmailException();
    }
    return true;
}

bool isValidName(const std::string &name)
{
    std::regex nameRegex(R"(^[a-zA-ZÀ-ỹ\s]+$)");
    if (name.empty() || !std::regex_match(name, nameRegex))
    {
        throw FullNameException();
    }
    return true;
}

bool isValidPhone(const std::string &phone)
{
    std::regex phoneRegex(R"(^0\d{9,14}$)");
    if (!std::regex_match(phone, phoneRegex))
    {
        throw PhoneException();
    }
    return true;
}

bool isValidCertificateID(const std::string &certificateID)
{
    if (certificateID.empty() || certificateID.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != std::string::npos)
    {
        throw CertificateIDException();
    }
    return true;
}

bool isValidCertificateName(const std::string &certificateName)
{
    if (certificateName.empty())
    {
        throw CertificateNameException();
    }
    return true;
}

bool isValidCertificateRank(const std::string &certificateRank)
{
    if (certificateRank.empty())
    {
        throw CertificateRankException();
    }
    return true;
}

bool isValidCertificateDate(const std::string &certificateDate)
{
    std::regex certificateDateRegex(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(\d{4})$)");
    if (!std::regex_match(certificateDate, certificateDateRegex))
    {
        throw CertificateDateException();
    }
    return true;
}

void checkCertificateInformation(const std::string &certificateID, const std::string &certificateName,
                                 const std::string &certificateRank, const std::string &certificateDate)
{
    isValidCertificateID(certificateID);

    isValidCertificateName(certificateName);

    isValidCertificateRank(certificateRank);

    isValidCertificateDate(certificateDate);
}