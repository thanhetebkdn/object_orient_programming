#include "Document.h"

Document::Document(std::string id, std::string publisher, int releaseCount)
    : id(id), publisher(publisher), releaseCount(releaseCount) {}

std::string Document::getId()
{
    return id;
}

void Document::inputInfor()
{
    std::cout << "Enter ID: " << id << std::endl;
    std::cin >> id;
    std::cout << "Enter Publisher : " << std::endl;
    std::cin >> publisher;
    std::cout << "Enter Release Count : " << std::endl;
    std::cin >> releaseCount;
}

void Document::displayInfor()
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Release Count: " << releaseCount << std::endl;
}
