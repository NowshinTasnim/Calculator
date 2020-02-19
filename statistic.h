#ifndef STATISTIC_H
#define STATISTIC_H
#include "common.h"

class Stat
{
protected:
    double minimum;
    double maximum;
    double frequency;
public:
    Stat(double mi,double ma,double freq);
    double getmin();
    double getmax();
    double getfreq();

};

class Data:public Stat
{
protected:
    double xi;
    double fixi;
public:
    Data(double mi,double ma,double freq,double xi,double fixi):Stat(mi,ma,freq)
    {
        this->xi=xi;
        this->fixi=fixi;
    }
    double getxi();
    double getfixi();
};

namespace mean
{
    class Mean
    {
        double avg;
    public:
        void setter(double a)
        {
            avg=a;
        }
        void getter()
        {
            cout<<"\n\n\t\tMEAN OF GIVEN DATA: "<<avg<<endl;
        }
    };
}

namespace standard
{
    class Sd
    {
        double devi;
    public:
        void setter(double d)
        {
            devi=d;
        }
        void getter()
        {
            cout<<"\n\n\t\tSTANDARD DAVIATION OF GIVEN DATA: "<<devi<<endl;
        }
    };
}
#endif
