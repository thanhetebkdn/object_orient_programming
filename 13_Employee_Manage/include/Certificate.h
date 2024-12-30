#ifndef CERTIFICATE_H
#define CERTIFICATE_H

#include <iostream>
#include <string>
class Certificate
{
public:
    Certificate();
    Certificate(std::string cerID, std::string cerName,
                std::string cerRank, std::string cerDate);
    void inputCer();
    void showCertificate() const;

private:
    std::string certificateID;
    std::string certificateName;
    std::string certificateRank;
    std::string certificateDate;
};

#endif