#include <iostream>
#include <memory>
#include "ManageStudent.h"
#include "Student.h"

int main()
{
    int choice;
    ManageStudent manageStudent;

    while (true)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a new student\n";
        std::cout << "2. Display students age 20\n";
        std::cout << "3. Display students age 23 from Da Nang\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            auto student = std::make_unique<Student>();
            student->inputInfor();
            manageStudent.addStudent(std::move(student));
            break;
        }
        case 2:
            manageStudent.displayStudentsWithAge20();
            break;
        case 3:
            manageStudent.displayStudentsFromDaNangWithAge23();
            break;
        case 4:
            manageStudent.exitProgram();
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
