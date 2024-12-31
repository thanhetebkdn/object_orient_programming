#ifndef PARTTIMESTUDENT_H
#define PARTTIMESTUDENT_H

#include <iostream>
#include "Student.h"

class PartTimeStudent : public Student
{
public:
    PartTimeStudent();
    PartTimeStudent(std::string student_id, std::string full_name, std::string dob,
                    float entry_score, int enrollment_year, std::string training_location);

    void inputInfor() override;
    void outputInfor() override;
    bool isFullTime() override;
    std::string getTrainingLocation();
    void setTrainingLocation(std::string location);

private:
    std::string training_location;
};

#endif