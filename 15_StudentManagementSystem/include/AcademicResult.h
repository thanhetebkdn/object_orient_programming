#ifndef ACADEMICRESULT_H
#define ACADEMICRESULT_H
#include <iostream>
#include <string>

class AcademicResult
{
private:
    std::string semester_name;
    float semester_gpa;

public:
    std::string getGPA();
    void inputResult();
    void outputResult();
};
#endif