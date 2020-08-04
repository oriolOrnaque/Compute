#include "multiply.h"

Multiply::Multiply(double factor)
{
    this->factor = factor;
}

Multiply::~Multiply()
{

}

double Multiply::compute(const double input) const
{
    return this->factor * input;
}

QString Multiply::toQString(void) const
{
    return "*" + QString::number(this->factor);
}
