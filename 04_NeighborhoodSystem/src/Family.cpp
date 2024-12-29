#include "Family.h"
Family::Family() {}
Family::Family(std::string houseNumber, int numberMember)
    : houseNumber(""), numberMember(0) {}

void Family::addMember(const Person &person)
{
    listPerson.push_back(person);
    numberMember++;
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