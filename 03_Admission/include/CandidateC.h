#ifndef CANDIDATEC_H
#define CANDIDATEC_H

#include <iostream>
#include "Candidate.h"
class CandidateC : public Candidate
{
public:
    CandidateC();
    CandidateC(std::string id, std::string name,
               std::string address, int priority);
    void inputInfor() override;
    void displayInfor() override;

private:
    const std::string subject = "Math, Chemistry,Biology";
};

#endif