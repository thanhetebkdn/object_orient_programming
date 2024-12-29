#include <Student.h>
#include <ManageStudent.h>

void ManageStudent::addStudent(std::unique_ptr<Student> student)
{
    student->inputInfor();
    listStudent.push_back(std::move(student));
}

void ManageStudent::displayStudent_O1() const
{
    std::cout << "List student age equal 20" << std::endl;
    for (const auto &s : listStudent)
    {
        if (s->getAge() == 20)
        {
            s->displayInfor();
        }
    }
}

void ManageStudent::displayStudent_O2() const
{
    std::cout << "List student age equal 20 && address is Da Nang" << std::endl;
    for (const auto &s : listStudent)
    {
        if (s->getAddress() == "DaNang" && s->getAge() == 23)
        {
            s->displayInfor();
        }
    }
}

void ManageStudent::exitProgram() const
{
    std::cout << "Exit the program...!";
    exit(0);
}