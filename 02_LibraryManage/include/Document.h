#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <string>

class Document
{
public:
    Document(std::string id, std::string publisher, int releaseCount);
    virtual void inputInfor();
    virtual void displayInfor();
    std::string getId();
    virtual ~Document() = default;

private:
    std::string id;
    std::string publisher;
    int releaseCount;
};

#endif