#include "Faculty.h"
#include <iostream>
#include <algorithm>
#include "PartTimeStudent.h"

Faculty::Faculty() : faculty_name("") {}

Faculty::Faculty(std::string name) : faculty_name(name) {}

void Faculty::addStudent(const std::shared_ptr<Student> &student)
{
    students.push_back(student);
}

int Faculty::countFullTimeStudents() const
{
    return std::count_if(students.begin(), students.end(), [](const std::shared_ptr<Student> &student)
                         { return student->isFullTime(); });
}

std::shared_ptr<Student> Faculty::findTopEntryScoreStudent() const
{
    if (students.empty())
        return nullptr;

    return *std::max_element(students.begin(), students.end(), [](const std::shared_ptr<Student> &a, const std::shared_ptr<Student> &b)
                             { return a->getEntryScore() < b->getEntryScore(); });
}

std::vector<std::shared_ptr<Student>> Faculty::getPartTimeStudentsByLocation(const std::string &location) const
{
    std::vector<std::shared_ptr<Student>> result;
    for (const auto &student : students)
    {
        auto partTimeStudent = std::dynamic_pointer_cast<PartTimeStudent>(student);
        if (partTimeStudent && partTimeStudent->getTrainingLocation() == location)
        {
            result.push_back(partTimeStudent);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Student>> Faculty::getHighGPAStudentsInLatestSemester(float threshold) const
{
    std::vector<std::shared_ptr<Student>> result;
    for (const auto &student : students)
    {
        for (const auto &resultPtr : student->getAcademicResults())
        {
            if (resultPtr && std::stof(resultPtr->getGPA()) >= threshold)
            {
                result.push_back(student);
                break;
            }
        }
    }
    return result;
}

std::shared_ptr<Student> Faculty::findTopGPAStudent() const
{
    std::shared_ptr<Student> topStudent = nullptr;
    float highestGPA = -1.0;

    for (const auto &student : students)
    {
        for (const auto &resultPtr : student->getAcademicResults())
        {
            if (resultPtr && std::stof(resultPtr->getGPA()) > highestGPA)
            {
                highestGPA = std::stof(resultPtr->getGPA());
                topStudent = student;
            }
        }
    }
    return topStudent;
}

void Faculty::sortStudentsByTypeAndYear()
{
    std::sort(students.begin(), students.end(), [](const std::shared_ptr<Student> &a, const std::shared_ptr<Student> &b)
              {
                  if (a->isFullTime() != b->isFullTime())
                      return a->isFullTime() > b->isFullTime();
                  return a->getEnrollmentYear() < b->getEnrollmentYear(); });
}

std::map<int, int> Faculty::countStudentsByEnrollmentYear() const
{
    std::map<int, int> yearCount;
    for (const auto &student : students)
    {
        yearCount[student->getEnrollmentYear()]++;
    }
    return yearCount;
}

void Faculty::inputFaculty()
{
    std::cout << "Enter faculty name: ";
    std::getline(std::cin, faculty_name);

    int num_students;
    std::cout << "Enter number of students: ";
    std::cin >> num_students;
    std::cin.ignore();

    students.resize(num_students);
    for (int i = 0; i < num_students; ++i)
    {
        std::cout << "Enter information for student " << i + 1 << ":\n";
        std::string type;
        std::cout << "Is the student full-time or part-time? (full/part): ";
        std::getline(std::cin, type);

        if (type == "part")
        {
            students[i] = std::make_shared<PartTimeStudent>();
        }
        else
        {
            students[i] = std::make_shared<Student>();
        }
        students[i]->inputInfor();
    }
}

void Faculty::outputFaculty() const
{
    std::cout << "Faculty Name: " << faculty_name << "\n";
    for (const auto &student : students)
    {
        student->outputInfor();
    }
}
