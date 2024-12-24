#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include "Document.h"
#include <iostream>
#include <string>

class Newspaper : public Document
{
public:
    Newspaper();
    Newspaper(std::string id, std::string publisher,
              int releaseCount, std::string releaseDate);
    void inputInfor();
    void displayInfor();

private:
    std::string releaseDate;
};

#endif