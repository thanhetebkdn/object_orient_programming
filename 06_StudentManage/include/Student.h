#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student
{
public:
    Student();
    Student(const std::string &name, int age, const std::string &address);

    void inputInfor();
    void displayInfor() const;

    int getAge() const;
    std::string getAddress() const;

private:
    std::string name;
    int age;
    std::string address;
};

#endif
