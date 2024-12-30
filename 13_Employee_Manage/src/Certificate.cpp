#include "Certificate.h"

Certificate::Certificate()
    : certificateID(""), certificateName(""),
      certificateRank(""), certificateDate("") {}

Certificate::Certificate(std::string cerID, std::string cerName,
                         std::string cerRank, std::string cerDate)
    : certificateID(cerID), certificateName(cerName),
      certificateRank(cerRank), certificateDate(cerDate) {}

void Certificate::inputCer()
{
    std::cout << "Enter your Certificate ID: ";
    std::getline(std::cin, certificateID);
    std::cout << "Enter your Certificate Name: ";
    std::getline(std::cin, certificateName);
    std::cout << "Enter your Certificate Rank: ";
    std::getline(std::cin, certificateRank);
    std::cout << "Enter your Certificate Date: ";
    std::getline(std::cin, certificateDate);
}

void Certificate::showCertificate() const
{
    std::cout << "Certidicate ID: " << certificateID << std::endl;
    std::cout << "Certidicate Name: " << certificateName << std::endl;
    std::cout << "Certidicate Rank: " << certificateRank << std::endl;
    std::cout << "Certidicate Date: " << certificateDate << std::endl;
}