#include "GoodStudent.h"
#include <iostream>

GoodStudent::GoodStudent() : gpa(0.0) {}

GoodStudent::GoodStudent(std::string fullName, std::string doB, std::string sex,
                         std::string phoneNumber, std::string universityName,
                         std::string gradeLevel, double gpa, std::string bestRewardName)
    : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}

double GoodStudent::GetGPA()
{
    return gpa;
}

void GoodStudent::ShowMyInfo()
{
    Student::ShowMyInfo();
    std::cout << "GPA: " << gpa << "\n"
              << "Best Reward Name: " << bestRewardName << std::endl;
}
