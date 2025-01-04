#include <Admision.h>
#include <Candidate.h>
#include <CandidateA.h>
#include <CandidateB.h>
#include <CandidateC.h>
#include <memory>
#include <vector>

void Admision::addCandidate()
{
    std::cout << "1. CandiateA - 2. CandidateB - 3. CandidateC" << std::endl;
    int select;
    std::cout << "Choose your opition: ";
    std::cin >> select;
    std::cin.ignore();

    std::shared_ptr<Candidate> candidate_n = nullptr;

    if (select == 1)
    {
        candidate_n = std::make_shared<CandidateA>("", "", "", 0);
    }
    else if (select == 2)
    {
        candidate_n = std::make_shared<CandidateB>("", "", "", 0);
    }
    else if (select == 3)
    {
        candidate_n = std::make_shared<CandidateC>("", "", "", 0);
    }
    else
    {
        std::cout << "Error select\n";
        return;
    }
    candidate_n->inputInfor();
    listCandidiate.push_back(candidate_n);
}

void Admision::displayCandidate()
{
    if (listCandidiate.empty())
    {
        std::cout << "List Candidate is empty...!";
    }

    for (auto x : listCandidiate)
    {
        x->displayInfor();
        std::cout << "-------------------\n";
    }
}
void Admision::findCandidate()
{
    bool isFind = false;
    std::string findID;
    std::cout << "Enter your ID find: ";
    std::cin.ignore();
    std::getline(std::cin, findID);

    for (auto &x : listCandidiate)
    {
        if (x->getId() == findID)
        {
            std::cout << "Found ID: " << findID << std::endl;
            x->displayInfor(); // To display found candidate info
            isFind = true;
            break;
        }
    }

    if (!isFind)
    {
        std::cout << "Candidate not found.\n";
    }
}

void Admision::exit()
{
    std::cout << "Exit the program";
}