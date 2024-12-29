#include <Student.h>

Student::Student() : name(""), age(0), address("") {}
Student::Student(std::string name, int age, std::string address)
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
    std::cout << "Enter your name:";
    std::cin >> name;
    std::cout << "Enter your age:";
    std::cin >> age;
    std::cout << "Enter your address:";
    std::cin >> address;
}

void Student::displayInfor() const
{
    std::cout << "Your Name: " << name << "\n";
    std::cout << "Your Age: " << age << "\n";
    std::cout << "Your Address: " << address << "\n";
}
