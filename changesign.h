#ifndef CHANGESIGN_H
#define CHANGESIGN_H

#include <QString>

#include "operation.h"

class ChangeSign : public Operation
{
public:
    ChangeSign();
    ~ChangeSign();

    double compute(const double input) const override;
    QString toQString() const override;
};

#endif // CHANGESIGN_H
