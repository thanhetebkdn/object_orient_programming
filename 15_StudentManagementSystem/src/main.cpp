#include <iostream>
#include <memory>
#include <vector>
#include "Faculty.h"
#include "Student.h"
#include "PartTimeStudent.h"

void showMenu()
{
    std::cout << "\n--- Menu ---\n";
    std::cout << "1. Add Faculty and Students\n";
    std::cout << "2. Show Faculty and Students\n";
    std::cout << "3. Count Full-Time Students\n";
    std::cout << "4. Find Student with Highest Entry Score\n";
    std::cout << "5. Find Part-Time Students by Location\n";
    std::cout << "6. Find Students with High GPA in Latest Semester\n";
    std::cout << "7. Find Student with Highest GPA\n";
    std::cout << "8. Sort Students by Type and Year\n";
    std::cout << "9. Count Students by Enrollment Year\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    Faculty faculty("Faculty of Computer Science");

    int choice;
    bool running = true;

    while (running)
    {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Bỏ qua ký tự newline trong input buffer

        switch (choice)
        {
        case 1: // Add Faculty and Students
            faculty.inputFaculty();
            break;

        case 2: // Show Faculty and Students
            faculty.outputFaculty();
            break;

        case 3: // Count Full-Time Students
            std::cout << "Number of full-time students: " << faculty.countFullTimeStudents() << std::endl;
            break;

        case 4: // Find Student with Highest Entry Score
        {
            auto topEntryScoreStudent = faculty.findTopEntryScoreStudent();
            if (topEntryScoreStudent)
            {
                std::cout << "Student with highest entry score: ";
                topEntryScoreStudent->outputInfor();
            }
            else
            {
                std::cout << "No students found.\n";
            }
        }
        break;

        case 5: // Find Part-Time Students by Location
        {
            std::string location;
            std::cout << "Enter training location: ";
            std::getline(std::cin, location);
            auto partTimeStudentsInLocation = faculty.getPartTimeStudentsByLocation(location);
            std::cout << "Part-time students in " << location << ":\n";
            for (const auto &student : partTimeStudentsInLocation)
            {
                student->outputInfor();
            }
        }
        break;

        case 6: // Find Students with High GPA in Latest Semester
        {
            auto highGPAStudents = faculty.getHighGPAStudentsInLatestSemester();
            std::cout << "Students with GPA >= 8.0 in the latest semester:\n";
            for (const auto &student : highGPAStudents)
            {
                student->outputInfor();
            }
        }
        break;

        case 7: // Find Student with Highest GPA
        {
            auto topGPAStudent = faculty.findTopGPAStudent();
            if (topGPAStudent)
            {
                std::cout << "Student with the highest GPA: ";
                topGPAStudent->outputInfor();
            }
            else
            {
                std::cout << "No students found.\n";
            }
        }
        break;

        case 8: // Sort Students by Type and Year
            faculty.sortStudentsByTypeAndYear();
            std::cout << "Students sorted by type and year:\n";
            faculty.outputFaculty();
            break;

        case 9: // Count Students by Enrollment Year
        {
            auto studentsByYear = faculty.countStudentsByEnrollmentYear();
            std::cout << "Students count by enrollment year:\n";
            for (const auto &entry : studentsByYear)
            {
                std::cout << "Year " << entry.first << ": " << entry.second << " students" << std::endl;
            }
        }
        break;

        case 0: // Exit
            running = false;
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice, please try again.\n";
            break;
        }
    }

    return 0;
}
