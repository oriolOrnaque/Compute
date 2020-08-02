#ifndef PROBLEMGENERATOR_H
#define PROBLEMGENERATOR_H

#include <QRandomGenerator>

#include <vector>

#include "problem.h"
#include "sum.h"

class ProblemGenerator
{
public:
    ProblemGenerator();
    ~ProblemGenerator();

    Problem* nextProblem(void);

protected:

private:
    std::vector<const Operation*> operations;
};

#endif // PROBLEMGENERATOR_H
