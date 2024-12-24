#ifndef MAGAZINE_H
#define MAGAZINE_H
#include <iostream>
#include <string>
#include "Document.h"

class Magazine : public Document
{
public:
    Magazine();
    Magazine(std::string id, std::string publisher,
             int releaseCount, int issueNumber, int releaseMonth);

    void inputInfor() override;
    void displayInfor() override;

private:
    int issueNumber;
    int releaseMonth;
};

#endif