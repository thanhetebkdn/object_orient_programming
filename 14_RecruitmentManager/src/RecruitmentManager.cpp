#include "RecruitmentManager.h"
#include <iostream>
#include <algorithm>

RecruitmentManager::RecruitmentManager() {}

void RecruitmentManager::AddStudent(std::shared_ptr<Student> student)
{
    students.push_back(student);
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

    // Phân loại sinh viên
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

    // Sắp xếp GoodStudent theo GPA, nếu bằng nhau thì sắp xếp theo fullName
    std::sort(goodStudents.begin(), goodStudents.end(), [](const std::shared_ptr<GoodStudent> &a, const std::shared_ptr<GoodStudent> &b)
              {
        if (a->GetGPA() != b->GetGPA()) {
            return a->GetGPA() > b->GetGPA();
        }
        return a->GetFullName() < b->GetFullName(); });

    // Sắp xếp NormalStudent theo entryTestScore, nếu bằng nhau thì sắp xếp theo englishScore, sau đó theo fullName
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

    // Lựa chọn ứng viên khá giỏi
    for (const auto &goodStudent : goodStudents)
    {
        if (selectedCount >= count)
            break;
        goodStudent->ShowMyInfo();
        std::cout << "-------------------" << std::endl;
        selectedCount++;
    }

    // Lựa chọn ứng viên trung bình nếu chưa đủ số lượng
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
    // Sắp xếp toàn bộ sinh viên trong danh sách giảm dần theo fullName và tăng dần theo phoneNumber
    std::sort(students.begin(), students.end(), [](const std::shared_ptr<Student> &a, const std::shared_ptr<Student> &b)
              {
                  if (a->GetFullName() != b->GetFullName())
                  {
                      return a->GetFullName() > b->GetFullName(); // Giảm dần theo fullName
                  }
                  return a->GetPhoneNumber() < b->GetPhoneNumber(); // Tăng dần theo phoneNumber
              });

    std::cout << "Students sorted successfully.\n";
}

void RecruitmentManager::InputStudent()
{
    int choice;
    std::cout << "Enter type of student (1: GoodStudent, 2: NormalStudent): ";
    std::cin >> choice;

    std::cin.ignore(); // Bỏ qua ký tự newline còn sót sau khi nhập số

    std::string fullName, doB, sex, phoneNumber, universityName, gradeLevel;

    std::cout << "Enter full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Enter date of birth (dd/MM/yyyy): ";
    std::getline(std::cin, doB);

    std::cout << "Enter gender: ";
    std::getline(std::cin, sex);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Enter university name: ";
    std::getline(std::cin, universityName);

    std::cout << "Enter grade level: ";
    std::getline(std::cin, gradeLevel);

    if (choice == 1)
    { // GoodStudent
        float gpa;
        std::string bestRewardName;

        std::cout << "Enter GPA: ";
        std::cin >> gpa;

        std::cin.ignore(); // Bỏ qua ký tự newline còn sót sau khi nhập số

        std::cout << "Enter best reward name: ";
        std::getline(std::cin, bestRewardName);

        auto goodStudent = std::make_shared<GoodStudent>(
            fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName);
        AddStudent(goodStudent);
    }
    else if (choice == 2)
    { // NormalStudent
        int englishScore, entryTestScore;

        std::cout << "Enter English score (TOEIC): ";
        std::cin >> englishScore;

        std::cout << "Enter entry test score: ";
        std::cin >> entryTestScore;

        auto normalStudent = std::make_shared<NormalStudent>(
            fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore);
        AddStudent(normalStudent);
    }
    else
    {
        std::cout << "Invalid choice! Returning to menu.\n";
    }
}
