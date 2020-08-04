#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <QString>

#include "operation.h"

class Multiply : public Operation
{
public:
    Multiply(double factor);
    ~Multiply();

    double compute(const double input) const;
    QString toQString(void) const;

protected:
    double factor;
};

#endif // MULTIPLY_H
