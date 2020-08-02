#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>

#include "operation.h"

class Problem
{
public:
    Problem(double start, int movs);
    Problem(double start, double goal, int movs);
    ~Problem(void);

    void input(const Operation* op);
    void reset(void);
    bool isSolved(void) const;

    int getCurrentMovs(void) const;
    double getCurrentValue(void) const;
    double getGoal(void) const;
    void addOperation(const Operation* op);
    QString getOperationQString(const size_t index) const;
    const Operation* getOperation(const size_t index) const;

    void setGoal(const double goal);

protected:
    int currentMovs;
    double currentValue;
    double goal;
    double start;
    int movs;
    std::vector<const Operation*> operations;

private:
};

#endif // PROBLEM_H
