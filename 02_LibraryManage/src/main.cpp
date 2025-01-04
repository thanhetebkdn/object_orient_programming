#include "DocumentManager.h"

int main()
{
    DocumentManager manager;

    while (true)
    {
        int choice;
        std::cout << "1. Add Document\n"
                  << "2. Remove Document\n"
                  << "3. Display Documents\n"
                  << "4. Search Document\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addDocument();
            break;
        case 2:
            manager.removeDocument();
            break;
        case 3:
            manager.displayDocuments();
            break;
        case 4:
            manager.searchByType();
            break;
        case 5:
            manager.exitProgram();
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
