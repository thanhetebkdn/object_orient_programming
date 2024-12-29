#include <Neighborhood.h>
#include <iostream>
int main()
{
    Neighborhood neighborhood;
    int n;
    std::cout << "Enter number of families: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::string houseNumber;
        int numberMember;
        std::cout << "Enter House number: ";
        std::cin >> houseNumber;

        std::cout << "Enter number member: ";
        std::cin >> numberMember;

        Family family(houseNumber, numberMember);

        for (int j = 0; j < numberMember; j++)
        {
            std::string name;
            std::string job;
            std::string id;
            int age;

            std::cout << "Enter infor detail: " << j + 1 << std::endl;
            std::cout << "Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Age: ";
            std::cin >> age;
            std::cout << "Job: ";
            std::cin.ignore();
            std::getline(std::cin, job);
            std::cout << "ID Card: ";
            std::cin >> id;

            try
            {
                Person person(id, name, age, job);
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
    std::cout << "Neighborhood Info:\n";
    neighborhood.getInfor();

    return 0;
}