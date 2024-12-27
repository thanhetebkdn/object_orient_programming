
#ifndef ADMISION
#define ADMISION
#include <iostream>
#include <vector>
#include <memory>
#include <Candidate.h>
class Admision
{
private:
    std::vector<std::shared_ptr<Candidate>> listCandidiate;

public:
    void addCandidate();
    void displayCandidate();
    void findCandidate();
    void exit();
};

#endif