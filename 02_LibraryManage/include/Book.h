#ifndef BOOK_H
#define BOOK_H
#include "Document.h"

class Book : public Document
{
public:
    Book();
    Book(std::string id, std::string publisher,
         int releaseCount, std::string author, int pages);
    void inputInfor() override;
    void displayInfor() override;

private:
    std::string author;
    int pages;
};

#endif