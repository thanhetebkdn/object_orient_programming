#include <CandidateB.h>

CandidateB::CandidateB() {}

void CandidateB ::inputInfor()
{
    Candidate::inputInfor();
}

void CandidateB::displayInfor()
{
    Candidate::displayInfor();
    std::cout << "Your subject: " << subject << std::endl;
}