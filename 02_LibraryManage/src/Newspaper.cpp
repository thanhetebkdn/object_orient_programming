#include "Newspaper.h"

Newspaper::Newspaper() : Document("", "", 0) {}
Newspaper::Newspaper(std::string id, std::string publisher,
                     int releaseCount, std::string releaseDate)
    : Document(id, publisher, releaseCount),
      releaseDate(releaseDate) {}

void Newspaper::inputInfor()
{
    Document::inputInfor();
    std::cout << "Enter Release Date: ";
    std::getline(std::cin, releaseDate);
}

void Newspaper::displayInfor()
{
    Document::displayInfor();
    std::cout << "Enter Release Date: " << releaseDate << std::endl;
}
