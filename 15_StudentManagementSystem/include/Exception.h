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
        return "Invalid birthday format! Please use DD/MM/YYYY.";
    }
};

class InvalidEntryScoreException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Entry score must be a valid number.";
    }
};

class InvalidEnrollmentYearException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Enrollment year must be a positive number.";
    }
};

class InvalidTrainingLocationException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Training location must be between 5 and 100 characters and contain only valid characters.";
    }
};

class InvalidFacultyNameException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Faculty name must be between 5 and 100 characters.";
    }
};

class InvalidNumberOfStudentsException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Number of students must be a positive integer.";
    }
};

class InvalidStudentIDException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Student ID must be 5-15 alphanumeric characters.";
    }
};

class InvalidScoreException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Score must be between 0.0 and 10.0.";
    }
};

class InvalidEmailException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Email is invalid! Please enter a correct email format.";
    }
};

class InvalidPhoneException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Phone number must be a valid number starting with 0 and 9-14 digits long.";
    }
};

#endif