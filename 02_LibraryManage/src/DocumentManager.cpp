#include <DocumentManager.h>
#include <Document.h>
#include <Book.h>
#include <Newspaper.h>
#include <Magazine.h>
#include <memory>
#include <vector>
#include <string>

void DocumentManager::addDocument()
{
    std::cout << "1. Book - 2.Magazine - 3. Newspaper\n";
    int select;
    std::cout << "Enter Type Document: ";
    std::cin >> select;

    std::unique_ptr<Document> document = nullptr;

    if (select == 1)
    {
        document = std::make_unique<Book>();
    }
    else if (select == 2)
    {
        document = std::make_unique<Magazine>();
    }
    else if (select == 3)
    {
        document = std::make_unique<Newspaper>();
    }
    else
    {
        std::cout << "Select error...!\n";
        return;
    }

    document->inputInfor();
    listDocument.push_back(std::move(document));
}
void DocumentManager::removeDocument()
{
    std::string typeRemove;
    std::cout << "Enter typeDocs that wants to remove....!";
    std::getline(std::cin, typeRemove);

    for (auto it = listDocument.begin(); it != listDocument.end(); it++)
    {
        if ((*it)->getId() == typeRemove)
        {
            listDocument.erase(it);
            std::cout << "Remove element " << typeRemove;
            break;
        }
    }
}
void DocumentManager::displayDocuments()
{
    if (listDocument.empty())
    {
        std::cout << "Lisst documents is empty...!\n";
        return;
    }

    for (auto &docs : listDocument)
    {
        docs->displayInfor();
        std::cout << "---------------------" << std::endl;
    }
}
void DocumentManager::searchByType()
{
    bool isFind = false;
    std::string typeDocs;
    std::cout << "Enter your Type Docs: ";
    std::getline(std::cin, typeDocs);

    for (auto &docs : listDocument)
    {
        if (docs->getId() == typeDocs)
        {
            std::cout << "Found type: " << typeDocs << std::endl;
            isFind = true;
            break;
            ;
        }
    }

    if (!isFind)
    {
        std::cout << typeDocs << " not found...!\n";
    }
}
void DocumentManager::exit()
{
    std::cout << "Exit the program....!\n";
}
