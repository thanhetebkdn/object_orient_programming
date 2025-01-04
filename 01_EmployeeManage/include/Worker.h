#ifndef WORKER_H
#define WORKER_H

#include "Employee.h"

class Worker : public Employee
{
public:
    Worker();
    Worker(const std::string &n, int a, const std::string &g, const std::string &addr, int lvl);
    void inputInfo() override;
    void displayInfo() const override;

private:
    int level;
};

#endif
