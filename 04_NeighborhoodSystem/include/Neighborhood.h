#ifndef NEIBORHOOD
#define NEIBORHOOD
#include <vector>
#include <iostream>
#include <Family.h>
class Neighborhood
{

public:
    Neighborhood();
    void addFamily(Family &family);
    void getInfor() const;

private:
    std::vector<Family> listFamily;
};

#endif