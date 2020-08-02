#include "problemgenerator.h"

ProblemGenerator::ProblemGenerator()
{
    this->operations.push_back(new Sum(5));
    this->operations.push_back(new Sum(2));
    this->operations.push_back(new Sum(41));
}

ProblemGenerator::~ProblemGenerator()
{
    for(auto it = this->operations.begin();
        it != this->operations.end();
        ++it)
    {
        delete *it;
    }
}

Problem* ProblemGenerator::nextProblem(void)
{
    QRandomGenerator* rand = QRandomGenerator::global();

    double start = rand->bounded(100000);
    int movs = 2 + rand->bounded(8);
    double goal = start;

    Problem* p = new Problem(start, movs);

    for(int i = 0; i < movs; ++i)
    {
        size_t idx = rand->bounded((double)this->operations.size());
        const Operation* op = this->operations.at(idx);
        goal = op->compute(goal);
        p->addOperation(op);
    }

    p->setGoal(goal);

    return p;
}
