#include <iostream>
#include "EmployeeManage.h"

void showMenu()
{
    std::cout << "\n========== Employee Management ==========\n"
              << "1. Add New Employee\n"
              << "2. Modify Employee by ID\n"
              << "3. Delete Employee by ID\n"
              << "4. Show All Employees\n"
              << "5. Exit Program\n"
              << "=========================================\n"
              << "Enter your choice: ";
}

int main()
{
    EmployeeManage employeeManage;
    int choice = 0;

    while (choice != 5)
    {
        showMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            employeeManage.addNewEmployee();
            break;

        case 2:
            employeeManage.modifyID();
            break;

        case 3:
            employeeManage.deleteByID();
            break;

        case 4:
            employeeManage.showAllEmployee();
            break;

        case 5:
            employeeManage.exitProgram();
            break;

        default:
            std::cerr << "Please try again.\n";
            break;
        }
    }

    return 0;
}
