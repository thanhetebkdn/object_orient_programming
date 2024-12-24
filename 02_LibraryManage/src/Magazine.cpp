#include <Magazine.h>

Magazine::Magazine() : Document("", "", 0) {};
Magazine::Magazine(std::string id, std::string publisher,
                   int releaseCount, int issueNumber, int releaseMonth)
    : Document(id, publisher, releaseCount),
      issueNumber(issueNumber), releaseMonth(releaseMonth) {}

void Magazine::inputInfor()
{
    Document::inputInfor();
    std::cout << "Enter IssueNumber: ";
    std::cin >> issueNumber;
    std::cout << "Enter Release Month: ";
    std::cin >> releaseMonth;
}

void Magazine::displayInfor()
{
    Document::displayInfor();
    std::cout << "Enter Author: " << issueNumber << std::endl;
    std::cout << "Enter Pages: " << releaseMonth << std::endl;
}