#ifndef POPRIGHT_H
#define POPRIGHT_H

#include <QString>
#include <cmath>

#include "operation.h"

class PopRight : public Operation
{
public:
    PopRight();
    ~PopRight(void);

    double compute(const double input) const override;
    QString toQString() const override;
};

#endif // POPRIGHT_H
