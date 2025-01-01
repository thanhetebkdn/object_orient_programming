#ifndef MANAGE_STUDENT_H
#define MANAGE_STUDENT_H

#include <iostream>
#include <vector>
#include <memory>
#include "Student.h"

class ManageStudent
{
public:
    void addStudent(std::unique_ptr<Student> student);
    void displayStudentsWithAge20() const;
    void displayStudentsFromDaNangWithAge23() const;
    void exitProgram() const;

private:
    std::vector<std::unique_ptr<Student>> listStudent;
};

#endif
