#include <Admision.h>

int main()
{
    Admision mana_candidate;
    while (1)
    {
        std::cout << "1. Add a new Candidate\n";
        std::cout << "2. Display list Candidate\n";
        std::cout << "3. Find a Candidate\n";
        std::cout << "4. Exit\n";
        int option;
        std::cout << "Slect your option...!: \n";
        std::cin >> option;

        switch (option)
        {
        case 1:
            mana_candidate.addCandidate();
            break;
        case 2:
            mana_candidate.displayCandidate();
            break;
        case 3:
            mana_candidate.findCandidate();
            break;
        case 4:
            mana_candidate.exit();
            return 0;
        default:
            std::cout << "Error option";
        }
    }

    return 0;
}