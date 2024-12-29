#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <set>
#include <sstream>

class Person
{
public:
    Person(std::string id, std::string name, int age, std::string job);
    std::string getInfor() const;
    static std::set<std::string> idSet;

private:
    std::string id;
    std::string name;
    int age;
    std::string job;
};

#endif
