#include "RecruitmentManager.h"
#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <regex>
#include "Exception.h"
#include "Validation.h"

RecruitmentManager::RecruitmentManager() {}

void RecruitmentManager::AddStudent(std::shared_ptr<Student> student)
{
    students.push_back(student);
}

void RecruitmentManager::InputStudent()
{
    int choice;
    while (true)
    {
        std::cout << "Enter type of student (1: GoodStudent, 2: NormalStudent): ";
        std::cin >> choice;

        try
        {
            isValidStudentType(choice);
            break;
        }
        catch (const InvalidStudentTypeException &e)
        {
            std::cout << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cin.ignore();

    std::string fullName, doB, sex, phoneNumber, universityName, gradeLevel;
    float gpa;
    std::string bestRewardName;
    int englishScore, entryTestScore;

    while (true)
    {
        std::cout << "Enter full name: ";
        std::getline(std::cin, fullName);
        try
        {
            isValidFullName(fullName);
            break;
        }
        catch (const InvalidFullNameException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Enter date of birth (dd/MM/yyyy): ";
        std::getline(std::cin, doB);
        try
        {
            isValidBirthday(doB);
            break;
        }
        catch (const InvalidDOBException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "Enter gender: ";
    std::getline(std::cin, sex);

    while (true)
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
        try
        {
            isValidPhoneNumber(phoneNumber);
            break;
        }
        catch (const InvalidPhoneNumberException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    try
    {
        isValidStudentType(choice);
    }
    catch (const InvalidStudentTypeException &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }

    while (true)
    {
        std::cout << "Enter university name: ";
        std::getline(std::cin, universityName);
        try
        {
            isValidUniversityName(universityName);
            break;
        }
        catch (const InvalidUniversityNameException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Enter grade level: ";
        std::getline(std::cin, gradeLevel);
        try
        {
            isValidGradeLevel(gradeLevel);
            break;
        }
        catch (const InvalidGradeLevelException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    if (choice == 1)
    {

        while (true)
        {
            std::cout << "Enter GPA: ";
            std::cin >> gpa;
            std::cin.ignore();
            try
            {
                isValidGPA(gpa);
                break;
            }
            catch (const InvalidGPAException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        while (true)
        {
            std::cout << "Enter best reward name: ";
            std::getline(std::cin, bestRewardName);
            try
            {
                isValidBestRewardName(bestRewardName);
                break;
            }
            catch (const InvalidBestRewardNameException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        auto goodStudent = std::make_shared<GoodStudent>(
            fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName);
        AddStudent(goodStudent);
    }
    else if (choice == 2)
    {

        while (true)
        {
            std::cout << "Enter English score (TOEIC): ";
            std::cin >> englishScore;
            try
            {
                isValidEnglishScore(englishScore);
                break;
            }
            catch (const InvalidEnglishScoreException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        while (true)
        {
            std::cout << "Enter entry test score: ";
            std::cin >> entryTestScore;
            try
            {
                isValidEntryTestScore(entryTestScore);
                break;
            }
            catch (const InvalidEntryTestScoreException &e)
            {
                std::cout << e.what() << std::endl;
            }
        }

        auto normalStudent = std::make_shared<NormalStudent>(
            fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore);
        AddStudent(normalStudent);
    }
}

void RecruitmentManager::DisplayAllStudents()
{
    std::cout << "=== All Students ===" << std::endl;
    for (const auto &student : students)
    {
        student->ShowMyInfo();
        std::cout << "-------------------" << std::endl;
    }
}

void RecruitmentManager::SelectCandidates(int count)
{
    if (count < 11 || count > 15)
    {
        std::cout << "Invalid number of candidates. Please choose between 11 and 15.\n";
        return;
    }

    std::vector<std::shared_ptr<GoodStudent>> goodStudents;
    std::vector<std::shared_ptr<NormalStudent>> normalStudents;

    for (const auto &student : students)
    {
        if (std::shared_ptr<GoodStudent> goodStudent = std::dynamic_pointer_cast<GoodStudent>(student))
        {
            goodStudents.push_back(goodStudent);
        }
        else if (std::shared_ptr<NormalStudent> normalStudent = std::dynamic_pointer_cast<NormalStudent>(student))
        {
            normalStudents.push_back(normalStudent);
        }
    }

    std::sort(goodStudents.begin(), goodStudents.end(), [](const std::shared_ptr<GoodStudent> &a, const std::shared_ptr<GoodStudent> &b)
              {
        if (a->GetGPA() != b->GetGPA()) {
            return a->GetGPA() > b->GetGPA();
        }
        return a->GetFullName() < b->GetFullName(); });

    std::sort(normalStudents.begin(), normalStudents.end(), [](const std::shared_ptr<NormalStudent> &a, const std::shared_ptr<NormalStudent> &b)
              {
        if (a->GetEntryTestScore() != b->GetEntryTestScore()) {
            return a->GetEntryTestScore() > b->GetEntryTestScore();
        }
        if (a->GetEnglishScore() != b->GetEnglishScore()) {
            return a->GetEnglishScore() > b->GetEnglishScore();
        }
        return a->GetFullName() < b->GetFullName(); });

    std::cout << "=== Selected Candidates ===" << std::endl;

    int selectedCount = 0;

    for (const auto &goodStudent : goodStudents)
    {
        if (selectedCount >= count)
            break;
        goodStudent->ShowMyInfo();
        std::cout << "-------------------" << std::endl;
        selectedCount++;
    }

    for (const auto &normalStudent : normalStudents)
    {
        if (selectedCount >= count)
            break;
        normalStudent->ShowMyInfo();
        std::cout << "-------------------" << std::endl;
        selectedCount++;
    }

    if (selectedCount < count)
    {
        std::cout << "Not enough candidates to fulfill the requirement.\n";
    }
}

void RecruitmentManager::SortStudents()
{

    std::sort(students.begin(), students.end(), [](const std::shared_ptr<Student> &a, const std::shared_ptr<Student> &b)
              {
                  if (a->GetFullName() != b->GetFullName())
                  {
                      return a->GetFullName() > b->GetFullName(); 
                  }
                  return a->GetPhoneNumber() < b->GetPhoneNumber(); });

    std::cout << "Students sorted successfully.\n";
}
