#include "Book.h"
#include <iostream>

Book::Book() : Document("", "", 0), author(""), pages(0) {}

Book::Book(const std::string &id, const std::string &publisher,
           int releaseCount, const std::string &author, int pages)
    : Document(id, publisher, releaseCount), author(author), pages(pages) {}

void Book::inputInfo()
{
    Document::inputInfo();
    std::cin.ignore();
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter Pages: ";
    std::cin >> pages;
}

void Book::displayInfo() const
{
    Document::displayInfo();
    std::cout << "Author: " << author << "\nPages: " << pages << std::endl;
}
