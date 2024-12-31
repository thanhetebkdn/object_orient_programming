#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student
{
private:
    std::string fullName;
    std::string doB;
    std::string sex;
    std::string phoneNumber;
    std::string universityName;
    std::string gradeLevel;

public:
    Student();
    Student(std::string fullName, std::string doB, std::string sex,
            std::string phoneNumber, std::string universityName, std::string gradeLevel);
    virtual ~Student();

    virtual void ShowMyInfo();
    std::string GetFullName();
    std::string GetPhoneNumber();
};

#endif
