#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Student.h"
#include <map>
#include <algorithm>

class Faculty
{
public:
    Faculty();
    Faculty(std::string name);
    void addStudent(const std::shared_ptr<Student> &student);
    int countFullTimeStudents() const;
    std::shared_ptr<Student> findTopEntryScoreStudent() const;
    std::vector<std::shared_ptr<Student>> getPartTimeStudentsByLocation(const std::string &location) const;
    std::vector<std::shared_ptr<Student>> getHighGPAStudentsInLatestSemester(float threshold = 8.0) const;
    std::shared_ptr<Student> findTopGPAStudent() const;
    void sortStudentsByTypeAndYear();
    std::map<int, int> countStudentsByEnrollmentYear() const;

    void inputFaculty();
    void outputFaculty() const;

private:
    std::string faculty_name;
    std::vector<std::shared_ptr<Student>> students;
};

#endif