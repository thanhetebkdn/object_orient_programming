#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

class Document
{
public:
    Document(const std::string &id, const std::string &publisher, int releaseCount);
    virtual void inputInfo();
    virtual void displayInfo() const;
    const std::string &getId() const;
    virtual ~Document() = default;

private:
    std::string id;
    std::string publisher;
    int releaseCount;
};

#endif
