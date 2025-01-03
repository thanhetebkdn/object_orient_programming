#ifndef VALID_H
#define VALID_H

#include <string>
#include "Exception.h"

bool isValidEmail(const std::string &email);
bool isValidName(const std::string &name);
bool isValidPhone(const std::string &phone);
bool isValidStudentID(const std::string &student_id);
bool isValidDate(const std::string &date);
bool isValidScore(double score);
bool isValidTrainingLocation(const std::string &location);
bool isValidFacultyName(const std::string &name);
bool isValidNumberOfStudents(int num_students);
bool isValidEnrollmentYear(int year);

#endif
