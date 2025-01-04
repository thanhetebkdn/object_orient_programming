#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

bool isValidFullName(const std::string &fullName);
bool isValidBirthday(const std::string &birthday);
bool isValidPhoneNumber(const std::string &phone);
bool isValidStudentType(int choice);
bool isValidUniversityName(const std::string &universityName);
bool isValidGradeLevel(const std::string &gradeLevel);
bool isValidGPA(float gpa);
bool isValidBestRewardName(const std::string &bestRewardName);
bool isValidEnglishScore(int englishScore);
bool isValidEntryTestScore(int entryTestScore);

#endif
