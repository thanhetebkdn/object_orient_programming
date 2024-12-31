#ifndef GOODSTUDENT_H
#define GOODSTUDENT_H

#include "Student.h"
#include <string>

class GoodStudent : public Student
{
private:
    double gpa;
    std::string bestRewardName;

public:
    GoodStudent();
    GoodStudent(std::string fullName, std::string doB, std::string sex,
                std::string phoneNumber, std::string universityName, std::string gradeLevel,
                double gpa, std::string bestRewardName);
    void ShowMyInfo() override;
    double GetGPA();
};

#endif // GOODSTUDENT_H
