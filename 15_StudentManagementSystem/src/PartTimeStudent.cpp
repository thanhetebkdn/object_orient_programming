#include <limits>
#include <regex>
#include "PartTimeStudent.h"
#include "Exception.h"
#include "Validation.h"

PartTimeStudent::PartTimeStudent()
    : Student(), training_location("") {}

PartTimeStudent::PartTimeStudent(std::string student_id, std::string full_name, std::string dob,
                                 float entry_score, int enrollment_year, std::string training_location)
    : Student(student_id, full_name, dob, entry_score, enrollment_year),
      training_location(training_location) {}

void PartTimeStudent::inputInfor()
{
    Student::inputInfor();

    std::cout << "Enter training location: ";
    std::getline(std::cin, training_location);
    try
    {
        isValidTrainingLocation(training_location);
    }
    catch (const InvalidTrainingLocationException &e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
}

void PartTimeStudent::outputInfor()
{
    Student::outputInfor();
    std::cout << "Training Location: " << training_location << std::endl;
}

std::string PartTimeStudent::getTrainingLocation()
{
    return training_location;
}

void PartTimeStudent::setTrainingLocation(std::string location)
{
    training_location = location;
}

bool PartTimeStudent::isFullTime()
{
    return false;
}
