#include "Family.h"
Family::Family()
    : houseNumber(""), numberMember(0) {}
Family::Family(std::string houseNumber, int numberMember)
    : houseNumber(houseNumber), numberMember(numberMember) {}
void Family::addMember(const Person &person)
{
    listPerson.push_back(person);
}

std::string Family::getInfor() const
{
    std::stringstream ss;
    ss << "House Number: " << houseNumber << "\n";
    ss << "Number of Members: " << numberMember << "\n";
    for (const auto &p : listPerson)
    {
        ss << p.getInfor();
    }
    return ss.str();
}