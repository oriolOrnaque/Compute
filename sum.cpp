#include "sum.h"

Sum::Sum(double term)
{
    this->term = term;
}

Sum::~Sum()
{

}

double Sum::compute(const double input) const
{
    return input + this->term;
}

QString Sum::toQString(void) const
{
    return "+" + QString::number(this->term);
}
