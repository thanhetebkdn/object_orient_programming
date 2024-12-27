#include <CandidateC.h>
CandidateC::CandidateC() {}

void CandidateC ::inputInfor()
{
    Candidate::inputInfor();
}

void CandidateC::displayInfor()
{
    Candidate::displayInfor();
    std::cout << "Your subject: " << subject << std::endl;
}