#include <CandidateB.h>

CandidateB::CandidateB() : Candidate("", "", "", 0) {}
CandidateB ::CandidateB(std::string id, std::string name,
                        std::string address, int priority)
    : Candidate(id, name, address, priority) {}

void CandidateB ::inputInfor()
{
    Candidate::inputInfor();
}

void CandidateB::displayInfor()
{
    Candidate::displayInfor();
    std::cout << "Your subject: " << subject << std::endl;
}