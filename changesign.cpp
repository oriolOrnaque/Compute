#include "changesign.h"

ChangeSign::ChangeSign()
{

}

ChangeSign::~ChangeSign()
{

}

double ChangeSign::compute(const double input) const
{
    return input * (-1);
}

QString ChangeSign::toQString() const
{
    return "+/-";
}
