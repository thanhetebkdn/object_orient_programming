#include "Student.h"
#include <limits>

Student::Student() : name(""), age(0), address("") {}

Student::Student(const std::string &name, int age, const std::string &address)
    : name(name), age(age), address(address) {}

int Student::getAge() const
{
    return age;
}

std::string Student::getAddress() const
{
    return address;
}

void Student::inputInfor()
{
    std::cout << "Enter your name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    while (!(std::cin >> age))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter your age: ";
    }

    std::cout << "Enter your address: ";
    std::cin.ignore();
    std::getline(std::cin, address);
}

void Student::displayInfor() const
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Address: " << address << "\n";
}
