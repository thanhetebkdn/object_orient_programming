#include "Neighborhood.h"

Neighborhood::Neighborhood() {}

void Neighborhood::addFamily(Family &family)
{
    listFamily.push_back(family);
}

void Neighborhood::getInfor() const
{
    for (const auto &family : listFamily)
    {
        std::cout << family.getInfor() << std::endl;
    }
}
