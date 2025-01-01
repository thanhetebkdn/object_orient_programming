#include "ManageStudent.h"

void ManageStudent::addStudent(std::unique_ptr<Student> student)
{
    listStudent.push_back(std::move(student));
}

void ManageStudent::displayStudentsWithAge20() const
{
    bool found = false;
    std::cout << "List of students age 20:\n";
    for (const auto &s : listStudent)
    {
        if (s->getAge() == 20)
        {
            s->displayInfor();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No students age 20 found.\n";
    }
}

void ManageStudent::displayStudentsFromDaNangWithAge23() const
{
    bool found = false;
    std::cout << "List of students age 23 from Da Nang:\n";
    for (const auto &s : listStudent)
    {
        if (s->getAge() == 23 && s->getAddress() == "DaNang")
        {
            s->displayInfor();
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "No students age 23 from Da Nang found.\n";
    }
}

void ManageStudent::exitProgram() const
{
    std::cout << "Exiting the program...\n";
    exit(0);
}
