#ifndef APPENDRIGHT_H
#define APPENDRIGHT_H

#include <QString>

#include "operation.h"

class AppendRight : public Operation
{
public:
    AppendRight(double num);
    ~AppendRight(void);

    double compute(const double input) const override;
    QString toQString() const override;

protected:
    double num;
};

#endif // APPENDRIGHT_H
