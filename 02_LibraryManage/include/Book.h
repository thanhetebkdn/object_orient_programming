#ifndef BOOK_H
#define BOOK_H

#include "Document.h"

class Book : public Document
{
public:
    Book();
    Book(const std::string &id, const std::string &publisher,
         int releaseCount, const std::string &author, int pages);
    void inputInfo() override;
    void displayInfo() const override;

private:
    std::string author;
    int pages;
};

#endif
