#ifndef SUM_H
#define SUM_H

#include <QString>

#include "operation.h"

class Sum : public Operation
{
public:
    Sum(double term);
    ~Sum();

    double compute(const double input) const;
    QString toQString(void) const;

protected:
    double term;
};

#endif // SUM_H
