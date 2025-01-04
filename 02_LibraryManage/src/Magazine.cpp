#include "Magazine.h"
#include <iostream>

Magazine::Magazine() : Document("", "", 0), issueNumber(0), releaseMonth(0) {}

Magazine::Magazine(const std::string &id, const std::string &publisher,
                   int releaseCount, int issueNumber, int releaseMonth)
    : Document(id, publisher, releaseCount), issueNumber(issueNumber), releaseMonth(releaseMonth) {}

void Magazine::inputInfo()
{
    Document::inputInfo();
    std::cout << "Enter Issue Number: ";
    std::cin >> issueNumber;
    std::cout << "Enter Release Month: ";
    std::cin >> releaseMonth;
}

void Magazine::displayInfo() const
{
    Document::displayInfo();
    std::cout << "Issue Number: " << issueNumber
              << "\nRelease Month: " << releaseMonth << std::endl;
}
