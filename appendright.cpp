#include "appendright.h"

AppendRight::AppendRight(double num)
{
    this->num = (int)num % 10;
}

AppendRight::~AppendRight()
{

}

double AppendRight::compute(const double input) const
{
    return (input * 10) + num;
}

QString AppendRight::toQString() const
{
    return QString::number(this->num);
}
