#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

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

#endif
