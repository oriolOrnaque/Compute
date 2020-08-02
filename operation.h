#ifndef OPERATION_H
#define OPERATION_H

#include <QString>

class Operation
{
public:
    virtual ~Operation() = 0;
    virtual double compute(const double input) const = 0;
    virtual QString toQString(void) const = 0;
};

#endif // OPERATION_H
