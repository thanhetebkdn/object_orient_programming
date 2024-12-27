#include <CandidateA.h>

CandidateA::CandidateA() {}

void CandidateA ::inputInfor()
{
    Candidate::inputInfor();
}

void CandidateA::displayInfor()
{
    Candidate::displayInfor();
    std::cout << "Your subject: " << subject << std::endl;
}