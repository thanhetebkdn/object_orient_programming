#ifndef VALID_H
#define VALID_H

#include <string>
#include "Exception.h"

bool isValidBirthday(const std::string &birthday);
bool isValidEmail(const std::string &email);
bool isValidName(const std::string &name);
bool isValidPhone(const std::string &phone);

void isValidCertificateCount(int certCount);
bool isValidCertificateID(const std::string &certificateID);
bool isValidCertificateName(const std::string &certificateName);
bool isValidCertificateRank(const std::string &certificateRank);
bool isValidCertificateDate(const std::string &certificateDate);

bool isValidExperienceYear(int expInYear);
bool isValidProfessionalSkill(int proSkill);

bool isValidGraduationDate(const std::string &graduationDate);
bool isValidGraduationRank(const std::string &graduationRank);
bool isValidEducation(const std::string &education);

bool isValidGraduationDate(const std::string &graduationDate);
bool isValidGraduationRank(const std::string &graduationRank);
bool isValidEducation(const std::string &education);

bool isValidMajor(const std::string &major);
bool isValidSemester(int semester);
bool isValidUniversityName(const std::string &universityName);

#endif
