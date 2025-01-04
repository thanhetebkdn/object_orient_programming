#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <vector>
#include <memory>
#include "Document.h"

class DocumentManager
{
public:
    void addDocument();
    void removeDocument();
    void displayDocuments() const;
    void searchByType() const;
    void exitProgram();

private:
    std::vector<std::unique_ptr<Document>> documentList;
};

#endif
