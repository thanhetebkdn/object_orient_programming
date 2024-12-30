#include <iostream>
#include "EmployeeManage.h"

void showMenu()
{
    std::cout << "========== Employee Management ==========\n";
    std::cout << "1. Add New Employee\n";
    std::cout << "2. Modify Employee by ID\n";
    std::cout << "3. Delete Employee by ID\n";
    std::cout << "4. Show All Employees\n";
    std::cout << "5. Exit Program\n";
    std::cout << "=========================================\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    EmployeeManage employeeManage;
    int choice = 0;

    while (choice != 5) // Thoát chương trình khi người dùng chọn 5
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
            std::cout << "Exiting program. Goodbye!\n";
            employeeManage.exitProgram();
            break;

        default:
            std::cerr << "Invalid choice! Please try again.\n";
            break;
        }
    }

    return 0;
}
