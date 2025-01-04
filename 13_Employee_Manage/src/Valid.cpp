#include "Valid.h"
#include "Exception.h"
#include <regex>
#include <cctype>
#include <set>

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

void isValidCertificateCount(int certCount)
{
    if (certCount <= 0)
    {
        throw CertificateCountException();
    }
}
bool isValidCertificateID(const std::string &certificateID)
{
    // ID phải là số nguyên và không được rỗng
    if (certificateID.empty() || certificateID.find_first_not_of("0123456789") != std::string::npos)
    {
        throw CertificateIDException();
    }
    return true;
}
bool isValidCertificateName(const std::string &certificateName)
{
    // Name phải là chuỗi ký tự, không chứa số hoặc ký tự đặc biệt
    std::regex nameRegex(R"(^[a-zA-ZÀ-ỹ\s]+$)");
    if (certificateName.empty() || !std::regex_match(certificateName, nameRegex))
    {
        throw CertificateNameException();
    }
    return true;
}
bool isValidCertificateRank(const std::string &certificateRank)
{
    // Rank phải là số nguyên từ 1 đến 10
    if (certificateRank.empty() || certificateRank.find_first_not_of("0123456789") != std::string::npos)
    {
        throw CertificateRankException();
    }

    int rank = std::stoi(certificateRank);
    if (rank < 1 || rank > 10)
    {
        throw CertificateRankException();
    }
    return true;
}
bool isValidCertificateDate(const std::string &certificateDate)
{
    // Định dạng ngày phải là dd/mm/yyyy
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

bool isValidExperienceYear(int expInYear)
{
    if (expInYear < 0)
    {
        throw ExperienceYearException();
    }
    return true;
}
bool isValidProfessionalSkill(int proSkill)
{
    if (proSkill < 0)
    {
        throw ProfessionalSkillException();
    }
    return true;
}

bool isValidGraduationDate(const std::string &graduationDate)
{
    // Định dạng ngày phải là dd/mm/yyyy
    std::regex graduationDateRegex(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(\d{4})$)");
    if (!std::regex_match(graduationDate, graduationDateRegex))
    {
        throw GraduationDateException();
    }
    return true;
}
bool isValidGraduationRank(const std::string &graduationRank)
{
    // Rank phải là một trong các giá trị cố định: "Excellent", "Good", "Fair", "Poor"
    const std::set<std::string> validRanks = {"Excellent", "Good", "Fair", "Poor"};
    if (validRanks.find(graduationRank) == validRanks.end())
    {
        throw GraduationRankException();
    }
    return true;
}
bool isValidEducation(const std::string &education)
{
    // Education không được rỗng và chỉ chứa chữ và khoảng trắng
    std::regex educationRegex(R"(^[a-zA-ZÀ-ỹ\s]+$)");
    if (education.empty() || !std::regex_match(education, educationRegex))
    {
        throw EducationException();
    }
    return true;
}

bool isValidMajor(const std::string &major)
{
    if (major.empty())
    {
        throw MajorException();
    }
    return true;
}
bool isValidSemester(int semester)
{
    if (semester < 1 || semester > 10)
    {
        throw SemesterException();
    }
    return true;
}
bool isValidUniversityName(const std::string &universityName)
{
    if (universityName.empty())
    {
        throw UniversityNameException();
    }
    return true;
}
