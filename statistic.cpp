#include "common.h"
#include "statistic.h"

Stat::Stat(double mi,double ma,double freq)
{
    minimum=mi;
    maximum=ma;
    frequency=freq;
}

double Stat::getmin()
{
    return minimum;
}

double Stat::getmax()
{
    return maximum;
}

double Stat::getfreq()
{
    return frequency;
}

double Data::getxi()
{
    return xi;
}
double Data::getfixi()
{
    return fixi;
}




