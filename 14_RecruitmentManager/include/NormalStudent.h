#ifndef NORMALSTUDENT_H
#define NORMALSTUDENT_H

#include "Student.h"
#include <string>

class NormalStudent : public Student
{
private:
    int englishScore;
    int entryTestScore;

public:
    NormalStudent();
    NormalStudent(std::string fullName, std::string doB, std::string sex,
                  std::string phoneNumber, std::string universityName, std::string gradeLevel,
                  int englishScore, int entryTestScore);
    int GetEnglishScore();
    int GetEntryTestScore();
    void ShowMyInfo() override;
};

#endif 
