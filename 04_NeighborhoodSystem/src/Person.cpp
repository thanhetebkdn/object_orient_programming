#include "Person.h"

std::set<std::string> Person::idSet;

Person::Person(std::string id, std::string name, int age, std::string job)
    : id(id), name(name), age(age), job(job)
{
    if (idSet.find(id) != idSet.end())
    {
        throw std::invalid_argument("Id already exists");
    }
    idSet.insert(id);
}

std::string Person::getInfor() const
{
    std::stringstream ss;
    ss << "Your Id: " << id << "\n";
    ss << "Your Name: " << name << "\n";
    ss << "Your Age: " << age << "\n";
    ss << "Your Job: " << job << "\n";
    return ss.str();
}
