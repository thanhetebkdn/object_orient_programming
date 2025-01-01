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

#endif