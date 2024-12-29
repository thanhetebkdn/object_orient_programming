#include <iostream>
#include "ManageStudent.h"
#include "Student.h"
#include <memory>

int main()
{
    int select;
    ManageStudent mns;
    while (1)
    {
        std::cout << "1. Add a new Student\n";
        std::cout << "2. Display Infor O_1\n";
        std::cout << "3. Display Infor O_2\n";
        std::cout << "4. Exist\n";

        std::cout << "Enter your option:";
        std::cin >> select;

        switch (select)
        {
        case 1:
        {
            auto student = std::make_unique<Student>();
            student->inputInfor();
            mns.addStudent(std::move(student));
        }
        break;
        case 2:
            mns.displayStudent_O1();
            break;
        case 3:
            mns.displayStudent_O2();
            break;
        case 4:
            mns.exitProgram();
            return 0;
        default:
            std::cout << "Enter your option is errorr";
        }
    }

    return 0;
}