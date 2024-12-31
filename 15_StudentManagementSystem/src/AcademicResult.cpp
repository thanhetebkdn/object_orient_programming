#include "AcademicResult.h"
#include <iomanip> // Để format số thực

void AcademicResult::inputResult()
{
    std::cout << "Enter semester name (e.g., Fall 2023): ";
    std::getline(std::cin, semester_name);

    std::cout << "Enter GPA for " << semester_name << ": ";
    std::cin >> semester_gpa; // Nhập GPA dưới dạng số thực
    std::cin.ignore();        // Bỏ qua ký tự newline trong input buffer
}

void AcademicResult::outputResult()
{
    std::cout << "Semester: " << semester_name << ", GPA: "
              << std::fixed << std::setprecision(2) << semester_gpa << std::endl; // Format GPA
}

std::string AcademicResult::getGPA()
{
    return std::to_string(semester_gpa); // Chuyển GPA từ float sang chuỗi
}
