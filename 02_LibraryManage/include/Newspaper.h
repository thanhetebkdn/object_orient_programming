#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "Document.h"

class Newspaper : public Document
{
public:
    Newspaper();
    Newspaper(const std::string &id, const std::string &publisher,
              int releaseCount, const std::string &releaseDate);
    void inputInfo() override;
    void displayInfo() const override;

private:
    std::string releaseDate;
};

#endif
