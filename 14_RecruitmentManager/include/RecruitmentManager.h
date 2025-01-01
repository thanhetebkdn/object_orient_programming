#ifndef RECRUITMENTMANAGER_H
#define RECRUITMENTMANAGER_H

#include "Student.h"
#include "GoodStudent.h"
#include "NormalStudent.h"
#include <memory>
#include <vector>

class RecruitmentManager
{
private:
    std::vector<std::shared_ptr<Student>> students;

public:
    RecruitmentManager();
    void AddStudent(std::shared_ptr<Student> student);
    void DisplayAllStudents();
    void SelectCandidates(int count);
    void SortStudents();
    void InputStudent();
};

#endif
