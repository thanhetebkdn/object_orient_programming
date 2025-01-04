#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Document.h"

class Magazine : public Document
{
public:
    Magazine();
    Magazine(const std::string &id, const std::string &publisher,
             int releaseCount, int issueNumber, int releaseMonth);
    void inputInfo() override;
    void displayInfo() const override;

private:
    int issueNumber;
    int releaseMonth;
};

#endif
