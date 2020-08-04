#ifndef PROBLEMGENERATOR_H
#define PROBLEMGENERATOR_H

#include <QRandomGenerator>

#include <vector>
#include <random>
#include <cstdlib>
#include <algorithm>

#include "problem.h"
#include "sum.h"
#include "multiply.h"
#include "appendright.h"
#include "popright.h"
#include "changesign.h"

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
