#include "DocumentManager.h"

int main()
{
    DocumentManager docsmng;
    while (1)
    {
        int select;
        std::cout << "1. Add a document\n";
        std::cout << "2. Remove a document\n";
        std::cout << "3. Display a document\n";
        std::cout << "4. Search a document\n";
        std::cout << "5. Exit program\n";
        std::cout << "Enter your choice: ";
        std::cin >> select;

        switch (select)
        {
        case 1:
            docsmng.addDocument();
            break;
        case 2:
            docsmng.removeDocument();
        case 3:
            docsmng.displayDocuments();
            break;
        case 4:
            docsmng.searchByType();
            break;
        case 5:
            docsmng.exit();
            return 0;
        default:
            std::cout << "Error select...!";
        }
    }

    return 0;
}