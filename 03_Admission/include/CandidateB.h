#ifndef CANDIDATEB_H
#define CANDIDATEB_H

#include <iostream>
#include "Candidate.h"
class CandidateB : public Candidate
{
public:
    CandidateB();
    CandidateB(std::string id, std::string name,
               std::string address, int priority);
    void inputInfor() override;
    void displayInfor() override;

private:
    const std::string subject = "Math, Chemistry,Biology";
};

#endif