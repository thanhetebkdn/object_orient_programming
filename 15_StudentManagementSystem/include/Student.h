#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "AcademicResult.h"

class Student
{
public:
    Student();
    Student(std::string student_id, std::string full_name, std::string dob,
            float entry_score, int enrollment_year);

    virtual void inputInfor();
    virtual void outputInfor();
    virtual bool isFullTime();
    float getEntryScore();
    int getEnrollmentYear() const;

    std::vector<std::shared_ptr<AcademicResult>> &getAcademicResults();

private:
    std::string student_id;
    std::string full_name;
    std::string dateBirthday;
    float entry_score;
    int enrollment_year;
    std::vector<std::shared_ptr<AcademicResult>> academic_results;
};

#endif