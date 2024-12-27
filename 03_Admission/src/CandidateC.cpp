#include <CandidateC.h>
CandidateC::CandidateC() : Candidate("", "", "", 0) {}
CandidateC::CandidateC(std::string id, std::string name,
                       std::string address, int priority)
    : Candidate(id, name, address, priority) {}

void CandidateC ::inputInfor()
{
    Candidate::inputInfor();
}

void CandidateC::displayInfor()
{
    Candidate::displayInfor();
    std::cout << "Your subject: " << subject << std::endl;
}