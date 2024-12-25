#include "Book.h"

Book::Book() : Document("", "", 0), author(""), pages(0) {}

Book::Book(std::string id, std::string publisher,
           int releaseCount, std::string author, int pages)
    : Document(id, publisher, releaseCount), author(author), pages(pages) {}

void Book::inputInfor()
{
    Document::inputInfor();
    std::cin.ignore();
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter Pages: ";
    std::cin >> pages;
}

void Book::displayInfor()
{
    Document::displayInfor();
    std::cout << "Enter Author: " << author << std::endl;
    std::cout << "Enter Pages: " << pages << std::endl;
}
