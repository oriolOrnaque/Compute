#include "problemgenerator.h"

ProblemGenerator::ProblemGenerator()
{
    for(int i = 2; i < 40; ++i)
    {
        this->operations.push_back(new Sum(i));
    }
    for(int i = -2; i < -40; i+=-2)
    {
        this->operations.push_back(new Sum(i));
    }
    for(int i = 0; i < 10; ++i)
    {
        this->operations.push_back(new AppendRight(i));
        this->operations.push_back(new Multiply(i));
        this->operations.push_back(new PopRight());
        this->operations.push_back(new ChangeSign());
    }
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
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<> normal_values(50, 200);
    std::normal_distribution<> normal_movs(4, 2);
    std::normal_distribution<> normal_more_movs(2, 1);

    double start = std::round(normal_values(gen));
    int movs = 1 + std::max(std::round(normal_movs(gen)), (double)0.0f);
    int padding_operations = std::max(std::round(normal_more_movs(gen)), (double)0.0f);
    double goal = start;

    Problem* p = new Problem(start, movs);

    for(int i = 0; i < movs + padding_operations; ++i)
    {
        size_t idx = rand() % this->operations.size();
        const Operation* op = this->operations.at(idx);
        p->addOperation(op);
    }

    for(int i = 0; i < movs; ++i)
    {
        size_t idx = rand() % (movs + padding_operations);
        const Operation* op = p->getOperation(idx);
        goal = op->compute(goal);
    }

    p->setGoal(goal);

    return p;
}
