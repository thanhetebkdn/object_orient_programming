#include "Newspaper.h"
#include <iostream>

Newspaper::Newspaper() : Document("", "", 0), releaseDate("") {}

Newspaper::Newspaper(const std::string &id, const std::string &publisher,
                     int releaseCount, const std::string &releaseDate)
    : Document(id, publisher, releaseCount), releaseDate(releaseDate) {}

void Newspaper::inputInfo()
{
    Document::inputInfo();
    std::cin.ignore();
    std::cout << "Enter Release Date: ";
    std::getline(std::cin, releaseDate);
}

void Newspaper::displayInfo() const
{
    Document::displayInfo();
    std::cout << "Release Date: " << releaseDate << std::endl;
}
