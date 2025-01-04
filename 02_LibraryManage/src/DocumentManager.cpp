#include "DocumentManager.h"
#include "Book.h"
#include "Magazine.h"
#include "Newspaper.h"
#include <iostream>
#include <algorithm>

void DocumentManager::addDocument()
{
    std::cout << "1. Book - 2. Magazine - 3. Newspaper\n";
    int choice;
    std::cout << "Enter Document Type: ";
    std::cin >> choice;

    std::unique_ptr<Document> document = nullptr;

    if (choice == 1)
        document = std::make_unique<Book>();
    else if (choice == 2)
        document = std::make_unique<Magazine>();
    else if (choice == 3)
        document = std::make_unique<Newspaper>();
    else
    {
        std::cout << "Invalid selection!\n";
        return;
    }

    document->inputInfo();
    documentList.push_back(std::move(document));
}

void DocumentManager::removeDocument()
{
    std::cin.ignore();
    std::string id;
    std::cout << "Enter ID to remove: ";
    std::getline(std::cin, id);

    auto it = std::remove_if(documentList.begin(), documentList.end(),
                             [&id](const std::unique_ptr<Document> &doc)
                             { return doc->getId() == id; });

    if (it != documentList.end())
    {
        documentList.erase(it, documentList.end());
        std::cout << "Document removed successfully.\n";
    }
    else
    {
        std::cout << "Document not found.\n";
    }
}

void DocumentManager::displayDocuments() const
{
    if (documentList.empty())
    {
        std::cout << "No documents to display.\n";
        return;
    }

    for (const auto &doc : documentList)
    {
        doc->displayInfo();
        std::cout << "---------------------\n";
    }
}

void DocumentManager::searchByType() const
{
    std::cin.ignore();
    std::string id;
    std::cout << "Enter ID to search: ";
    std::getline(std::cin, id);

    for (const auto &doc : documentList)
    {
        if (doc->getId() == id)
        {
            doc->displayInfo();
            return;
        }
    }
    std::cout << "Document not found.\n";
}

void DocumentManager::exitProgram()
{
    std::cout << "Exiting program...\n";
}
