#include "EmployeeManager.h"
#include <iostream>

int main()
{
    EmployeeManager manager;
    bool isRunning = true;

    while (isRunning)
    {
        int choice;
        std::cout << "1. Add new employee\n"
                  << "2. Search employee by name\n"
                  << "3. Display all employees\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addNewEmployee();
            break;
        case 2:
            manager.searchByName();
            break;
        case 3:
            manager.displayAll();
            break;
        case 4:
            isRunning = false;
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
