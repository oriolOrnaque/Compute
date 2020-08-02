#include "problem.h"

Problem::Problem(double start, int movs)
{
    this->start = start;
    this->currentValue = start;
    this->currentMovs = movs;
    this->movs = movs;
}

Problem::Problem(double start, double goal, int movs)
{
    this->start = start;
    this->currentValue = start;
    this->goal = goal;
    this->currentMovs = movs;
    this->movs = movs;
}

Problem::~Problem(void)
{/*
    for(auto it = this->operations.begin();
        it != this->operations.end();
        ++it)
    {
        delete *it;
    }
*/
}

void Problem::input(const Operation* op)
{
    if(this->currentMovs > 0 && !isSolved())
    {
        this->currentValue = op->compute(this->currentValue);
        --(this->currentMovs);
    }
}

void Problem::reset(void)
{
    this->currentMovs = this->movs;
    this->currentValue = this->start;
}

bool Problem::isSolved(void) const
{
    return this->currentValue == this->goal;
}

int Problem::getCurrentMovs() const
{
    return this->currentMovs;
}

double Problem::getCurrentValue() const
{
    return this->currentValue;
}

double Problem::getGoal(void) const
{
    return this->goal;
}

void Problem::addOperation(const Operation* op)
{
    this->operations.push_back(op);
}

QString Problem::getOperationQString(const size_t index) const
{
    return this->getOperation(index)->toQString();
}

const Operation* Problem::getOperation(const size_t op_idx) const
{
    try {
        return this->operations.at(op_idx);
    } catch (const std::out_of_range& e) {
        return nullptr;
    }
}

void Problem::setGoal(const double goal)
{
    this->goal = goal;
}
