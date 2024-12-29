#ifndef FAMILY_H
#define FAMILY_H

#include <iostream>
#include <string>
#include <Person.h>
#include <vector>
#include <sstream>

class Family
{

public:
    Family();
    Family(std::string houseNumber, int numberMember);
    void addMember(const Person &person);
    std::string getInfor() const;

private:
    std::string houseNumber;
    int numberMember;
    std::vector<Person> listPerson;
};

#endif