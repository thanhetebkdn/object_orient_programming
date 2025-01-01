#include "Student.h"
#include "AcademicResult.h"
#include "Exception.h"
#include <limits>

Student::Student()
    : student_id(""), full_name(""), dateBirthday(""), entry_score(0.0), enrollment_year(0) {}

Student::Student(std::string student_id, std::string full_name, std::string dob,
                 float entry_score, int enrollment_year)
    : student_id(student_id), full_name(full_name), dateBirthday(dob),
      entry_score(entry_score), enrollment_year(enrollment_year) {}

void Student::inputInfor()
{
    try
    {
        std::cout << "Enter student ID: ";
        std::getline(std::cin, student_id);

        // Kiểm tra họ tên
        while (true)
        {
            std::cout << "Enter full name: ";
            std::getline(std::cin, full_name);

            if (full_name.length() < 10 || full_name.length() > 50)
            {
                throw InvalidFullNameException();
            }
            break;
        }

        // Kiểm tra ngày sinh
        while (true)
        {
            std::cout << "Enter birth date (DD/MM/YYYY): ";
            std::getline(std::cin, dateBirthday);

            std::regex dobPattern(R"(\d{2}/\d{2}/\d{4})");
            if (!std::regex_match(dateBirthday, dobPattern))
            {
                throw InvalidDOBException();
            }
            break;
        }

        // Kiểm tra điểm đầu vào
        while (true)
        {
            std::cout << "Enter entry score: ";
            std::cin >> entry_score;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidEntryScoreException();
            }
            break;
        }
        std::cin.ignore(); // Bỏ qua ký tự newline còn sót sau khi nhập số

        // Kiểm tra năm nhập học
        while (true)
        {
            std::cout << "Enter enrollment year: ";
            std::cin >> enrollment_year;

            if (enrollment_year <= 0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InvalidEnrollmentYearException();
            }
            break;
        }
        std::cin.ignore();

        // Kiểm tra số kết quả học tập
        int num_results;
        while (true)
        {
            std::cout << "Enter number of academic results: ";
            std::cin >> num_results;

            if (num_results <= 0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Number of results must be greater than 0.\n";
                continue;
            }
            break;
        }
        std::cin.ignore();

        academic_results.resize(num_results);
        for (int i = 0; i < num_results; ++i)
        {
            std::cout << "Enter result for semester " << i + 1 << ":\n";
            academic_results[i] = std::make_shared<AcademicResult>();
            academic_results[i]->inputResult();
        }
    }
    catch (const InvalidFullNameException &e)
    {
        std::cout << e.what() << std::endl;
        inputInfor(); // Thử nhập lại thông tin
    }
    catch (const InvalidDOBException &e)
    {
        std::cout << e.what() << std::endl;
        inputInfor();
    }
    catch (const InvalidEntryScoreException &e)
    {
        std::cout << e.what() << std::endl;
        inputInfor();
    }
    catch (const InvalidEnrollmentYearException &e)
    {
        std::cout << e.what() << std::endl;
        inputInfor();
    }
}
void Student::outputInfor()
{
    std::cout << "Student ID: " << student_id << "\n";
    std::cout << "Full Name: " << full_name << "\n";
    std::cout << "Birth Date: " << dateBirthday << "\n";
    std::cout << "Entry Score: " << entry_score << "\n";
    std::cout << "Enrollment Year: " << enrollment_year << "\n";
    std::cout << "Academic Results: \n";
    for (const auto &result : academic_results)
    {
        result->outputResult(); // Giả sử bạn có phương thức `outputResult()` trong `AcademicResult`
    }
}

bool Student::isFullTime()
{
    if (entry_score >= 5.0)
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        int current_year = now->tm_year + 1900;

        if (enrollment_year <= current_year)
        {
            return true;
        }
    }
    return false;
}

float Student::getEntryScore()
{
    return entry_score;
}

std::vector<std::shared_ptr<AcademicResult>> &Student::getAcademicResults()
{
    return academic_results;
}

int Student::getEnrollmentYear() const
{
    return enrollment_year; // Trả về năm nhập học của sinh viên
}