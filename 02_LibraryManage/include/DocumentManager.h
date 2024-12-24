#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H
#include <iostream>
#include <memory>
#include <vector>
#include "Document.h"

class DocumentManager
{
public:
    void addDocument();
    void removeDocument();
    void displayDocuments();
    void searchByType();
    void exit();

private:
    std::vector<std::unique_ptr<Document>> listDocument;
};

#endif