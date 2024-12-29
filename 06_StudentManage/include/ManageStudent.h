#ifndef MANAGE_STUDENT_H
#define MANAGE_STUDENT_H
#include <iostream>
#include <vector>
#include <memory>
#include <Student.h>
class ManageStudent
{
public:
    void addStudent(std::unique_ptr<Student> student);
    void displayStudent_O1() const; // Your age student = 20
    void displayStudent_O2() const; // Your age student = 23 && address = DaNang
    void exitProgram() const;

private:
    std::vector<std::unique_ptr<Student>> listStudent;
};
#endif
