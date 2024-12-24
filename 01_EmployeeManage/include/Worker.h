#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"

class Worker : public Employee
{
public:
    Worker();
    Worker(std::string n, int a, std::string g, std::string addr, int lvl);
    void inputInfo() override;
    void displayInfo() override;

private:
    int level;
};

#endif // WORKER_H
