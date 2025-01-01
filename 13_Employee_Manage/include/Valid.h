#ifndef VALID_H
#define VALID_H

#include <string>
#include "Exception.h"

// Phương thức kiểm tra thông tin cá nhân
bool isValidBirthday(const std::string &birthday);
bool isValidEmail(const std::string &email);
bool isValidName(const std::string &name);
bool isValidPhone(const std::string &phone);

// Phương thức kiểm tra thông tin chứng chỉ
bool isValidCertificateID(const std::string &certificateID);
bool isValidCertificateName(const std::string &certificateName);
bool isValidCertificateRank(const std::string &certificateRank);
bool isValidCertificateDate(const std::string &certificateDate);

#endif
