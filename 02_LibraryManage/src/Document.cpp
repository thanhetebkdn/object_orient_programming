#include "Document.h"

Document::Document(const std::string &id, const std::string &publisher, int releaseCount)
    : id(id), publisher(publisher), releaseCount(releaseCount) {}

const std::string &Document::getId() const
{
    return id;
}

void Document::inputInfo()
{
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Publisher: ";
    std::cin >> publisher;
    std::cout << "Enter Release Count: ";
    std::cin >> releaseCount;
}

void Document::displayInfo() const
{
    std::cout << "ID: " << id << "\nPublisher: " << publisher
              << "\nRelease Count: " << releaseCount << std::endl;
}
