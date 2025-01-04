#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class BirthdayException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid birthday format. Please use dd/mm/yyyy.";
    }
};

class PhoneException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid phone number. Phone number must start with 0 and contain 10 to 15 digits.";
    }
};

class EmailException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid email format.";
    }
};

class FullNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Full Name is invalid. Only letters and spaces are allowed.";
    }
};

class CertificateIDException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid certificate ID. It cannot be empty or contain invalid characters.";
    }
};

class CertificateNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid certificate name. It cannot be empty.";
    }
};

class CertificateRankException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid certificate rank. It cannot be empty.";
    }
};

class CertificateDateException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid certificate date. It must be in dd/mm/yyyy format.";
    }
};

class ExperienceYearException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Experience Year cannot be negative.";
    }
};

class ProfessionalSkillException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Professional Skill cannot be negative.";
    }
};

class CertificateCountException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid certificate count. The number of certificates must be a positive integer.";
    }
};

class GraduationDateException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid graduation date. Please use dd/mm/yyyy format.";
    }
};

class GraduationRankException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Graduation rank must be a valid string.";
    }
};

class EducationException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Education field cannot be empty.";
    }
};

class MajorException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Major cannot be empty.";
    }
};
class SemesterException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Semester must be a valid integer between 1 and 10.";
    }
};
class UniversityNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "University name cannot be empty.";
    }
};

#endif