#ifndef ACADEMICRESULT_H
#define ACADEMICRESULT_H
#include <iostream>
#include <string>

class AcademicResult
{
private:
    std::string semester_name; // Tên học kỳ
    float semester_gpa;        // GPA dưới dạng số thực

public:
    std::string getGPA(); // Lấy GPA dưới dạng chuỗi
    void inputResult();   // Nhập kết quả học kỳ
    void outputResult();  // Xuất kết quả học kỳ
};
#endif