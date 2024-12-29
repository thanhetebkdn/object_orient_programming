#include <Neighborhood.h>

#include <iostream>
int main()
{
    Neighborhood neighborhood;
    int n;
    std::cout << "Enter number of families: ";
    std::cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int houseNumber;
        int numberMember;
        std::cout << "Enter House number: ";
        std::cin >> houseNumber;

        Family family(houseNumber, numberMember);

        std::cout << "Enter number member: ";
        std::cin >> numberMember;

        for (size_t j = 0; j < numberMember; j++)
        {
            std::string name;
            std::string job;
            std::string id;
            int age;

            std::cout << "Enter infor deteail: " << j + 1 << std::endl;
            std::cout << "Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Age: ";
            std::cin >> age;
            std::cout << "Occupation: ";
            std::cin.ignore();
            std::getline(std::cin, job);
            std::cout << "ID Card: ";
            std::cin >> id;

            try
            {
                Person person(name, age, job, id);
                family.addMember(person);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << e.what() << std::endl;
                j--;
            }
        }
        neighborhood.addFamily(family);
    }
    std::cout << "Neighborhood Infor:\n";
    neighborhood.getInfor();

    return 0;
}