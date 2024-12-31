#include "Student.h"

Student::Student() {}

Student::Student(std::string fullName, std::string doB, std::string sex,
                 std::string phoneNumber, std::string universityName, std::string gradeLevel)
    : fullName(fullName), doB(doB), sex(sex), phoneNumber(phoneNumber),
      universityName(universityName), gradeLevel(gradeLevel) {}

Student::~Student() {}

void Student::ShowMyInfo()
{
    std::cout << "Full Name: " << fullName << "\n"
              << "Date of Birth: " << doB << "\n"
              << "Sex: " << sex << "\n"
              << "Phone Number: " << phoneNumber << "\n"
              << "University: " << universityName << "\n"
              << "Grade Level: " << gradeLevel << std::endl;
}

std::string Student::GetFullName()
{
    return fullName;
}

std::string Student::GetPhoneNumber()
{
    return phoneNumber;
}
