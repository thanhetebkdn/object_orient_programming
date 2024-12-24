#include "EmployeeManager.h"
#include <iostream>

int main()
{
    EmployeeManager manager;

    while (1)
    {
        int choice;
        std::cout << "1. Add new employee\n";
        std::cout << "2. Search employee by name\n";
        std::cout << "3. Display all employees\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
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
            manager.exitProgram();
            return 0;
        default:
            std::cout << "Invalid choice";
        }
    }

    return 0;
}
