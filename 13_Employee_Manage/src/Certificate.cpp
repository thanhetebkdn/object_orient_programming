#include "Certificate.h"
#include "Valid.h"
#include "Exception.h"
#include <iostream>
#include <string>

Certificate::Certificate()
    : certificateID(""), certificateName(""),
      certificateRank(""), certificateDate("") {}

void Certificate::inputCer()
{
    do
    {
        std::cout << "Enter your Certificate ID: ";
        std::getline(std::cin, certificateID);
        try
        {
            isValidCertificateID(certificateID);
            break;
        }
        catch (const CertificateIDException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);

    do
    {
        std::cout << "Enter your Certificate Name: ";
        std::getline(std::cin, certificateName);
        try
        {
            isValidCertificateName(certificateName);
            break;
        }
        catch (const CertificateNameException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);

    do
    {
        std::cout << "Enter your Certificate Rank: ";
        std::getline(std::cin, certificateRank);
        try
        {
            isValidCertificateRank(certificateRank);
            break;
        }
        catch (const CertificateRankException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);

    do
    {
        std::cout << "Enter your Certificate Date (dd/mm/yyyy): ";
        std::getline(std::cin, certificateDate);
        try
        {
            isValidCertificateDate(certificateDate);
            break;
        }
        catch (const CertificateDateException &e)
        {
            std::cerr << e.what() << std::endl;
        }
    } while (true);
}

void Certificate::showCertificate() const
{
    std::cout << "Certificate ID: " << certificateID << std::endl;
    std::cout << "Certificate Name: " << certificateName << std::endl;
    std::cout << "Certificate Rank: " << certificateRank << std::endl;
    std::cout << "Certificate Date: " << certificateDate << std::endl;
}
