#include <limits>
#include <Candidate.h>

Candidate::Candidate(std::string id, std::string name,
                     std::string address, int priority)
    : id(id), name(name), address(address), priority(priority) {}

std::string Candidate::getId()
{
    return id;
}
void Candidate::inputInfor()
{

    std::cout << "Enter your id: ";
    std::getline(std::cin, id);

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your address: ";
    std::getline(std::cin, address);

    std::cout << "Enter your priority: ";
    while (!(std::cin >> priority))
    {
        std::cin.clear();                                                   // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore invalid input
        std::cout << "Invalid input. Enter a valid priority: ";
    }
}

void Candidate::displayInfor()
{
    std::cout << "Your id: " << id << std::endl;
    std::cout << "Your name: " << name << std::endl;
    std::cout << "Your address: " << address << std::endl;
    std::cout << "Your priority: " << priority << std::endl;
}
