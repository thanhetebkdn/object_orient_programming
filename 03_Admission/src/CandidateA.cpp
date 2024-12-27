#include <CandidateA.h>

CandidateA::CandidateA() : Candidate("", "", "", 0) {}
CandidateA::CandidateA(std::string id, std::string name,
                       std::string address, int priority)
    : Candidate(id, name, address, priority) {}

void CandidateA ::inputInfor()
{
    Candidate::inputInfor();
}

void CandidateA::displayInfor()
{
    Candidate::displayInfor();
    std::cout << "Your subject: " << subject << std::endl;
}