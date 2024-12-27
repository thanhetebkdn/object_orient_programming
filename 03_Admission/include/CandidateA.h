#ifndef CANDIDATEA_H
#define CANDIDATEA_H

#include <iostream>
#include "Candidate.h"
class CandidateA : public Candidate
{
public:
    CandidateA();
    CandidateA(std::string id, std::string name,
               std::string address, int priority);
    void inputInfor() override;
    void displayInfor() override;

private:
    const std::string subject = "Math, Physic,Chemistry";
};

#endif