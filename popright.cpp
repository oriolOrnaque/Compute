#include "popright.h"

PopRight::PopRight()
{

}

PopRight::~PopRight()
{

}

double PopRight::compute(const double input) const
{
    return floor(input / 10);
}

QString PopRight::toQString() const
{
    return "<<";
}
