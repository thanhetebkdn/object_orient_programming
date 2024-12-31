#include "NormalStudent.h"
#include <iostream>

NormalStudent::NormalStudent() : englishScore(0), entryTestScore(0) {}

NormalStudent::NormalStudent(std::string fullName, std::string doB, std::string sex,
                             std::string phoneNumber, std::string universityName,
                             std::string gradeLevel, int englishScore, int entryTestScore)
    : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel),
      englishScore(englishScore), entryTestScore(entryTestScore) {}

int NormalStudent::GetEntryTestScore()
{
    return entryTestScore;
}

int NormalStudent::GetEnglishScore()
{
    return englishScore;
}

void NormalStudent::ShowMyInfo()
{
    Student::ShowMyInfo();
    std::cout << "English Score: " << englishScore << "\n"
              << "Entry Test Score: " << entryTestScore << std::endl;
}
