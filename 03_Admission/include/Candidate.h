#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <string>
class Candidate
{
public:
    Candidate();
    Candidate(std::string id, std::string name,
              std::string address, int priority);

    std::string getId();
    virtual void inputInfor();
    virtual void displayInfor();
    virtual ~Candidate() = default;

private:
    std::string id;
    std::string name;
    std::string address;
    int priority;
};

#endif