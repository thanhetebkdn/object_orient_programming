#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class InvalidFullNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Full Name is invalid. Only letters and spaces are allowed.";
    }
};

class InvalidDOBException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid birthday format. Please use dd/mm/yyyy.";
    }
};

class InvalidPhoneNumberException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid phone number! It must be 10 digits long and start with 090, 098, 091, 031, 035, or 038.";
    }
};

class InvalidStudentTypeException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid student type! Please enter 1 for GoodStudent or 2 for NormalStudent.";
    }
};

class InvalidUniversityNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "University name must not be empty.";
    }
};

class InvalidGradeLevelException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Grade level must not be empty.";
    }
};

class InvalidGPAException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "GPA must be between 0 and 10.";
    }
};

class InvalidBestRewardNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Best reward name must not be empty.";
    }
};

class InvalidEnglishScoreException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "English score must be between 0 and 990.";
    }
};

class InvalidEntryTestScoreException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Entry test score must be between 0 and 100.";
    }
};

#endif
