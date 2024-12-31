#include "RecruitmentManager.h"
#include <iostream>

int main()
{
    RecruitmentManager manager;

    int option;
    do
    {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Add a Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Sort Students\n";
        std::cout << "4. Select Candidates\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            manager.InputStudent();
            break;
        case 2:
            manager.DisplayAllStudents();
            break;
        case 3:
            manager.SortStudents();
            std::cout << "Students sorted successfully.\n";
            break;
        case 4:
        {
            int count;
            std::cout << "Enter number of candidates to select: ";
            std::cin >> count;
            manager.SelectCandidates(count);
            break;
        }
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (option != 5);

    return 0;
}
