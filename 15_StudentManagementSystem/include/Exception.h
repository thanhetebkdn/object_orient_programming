#include <stdexcept>
#include <regex>
#include <iostream>

class InvalidFullNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Full name must be between 10 and 50 characters.";
    }
};

class InvalidDOBException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid birthday format! Please use DD/MM/YYYY.";
    }
};

class InvalidEntryScoreException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Entry score must be a valid integer!";
    }
};

class InvalidEnrollmentYearException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Enrollment year must be a valid year!";
    }
};
