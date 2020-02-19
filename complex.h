#ifndef COMPLEX_H
#define COMPLEX_H
#include "common.h"
class Complex
{
    double real;
    double img;
    public:
        Complex();
        Complex(Complex &obj);
        double getComp();
        void setComp(double real,double img);
        Complex operator+(Complex& c);
        Complex operator-(Complex& c);
        Complex operator*(Complex& c);
        Complex operator*(int num);
};
#endif
