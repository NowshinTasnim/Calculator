#ifndef VECTOR_H
#define VECTOR_H
#include "common.h"

class Vector
{
    double i,j,k;
public:
    Vector();
    Vector(double i,double j,double k);
    Vector(Vector& obj);
    geti();
    getj();
    getk();
    setdata(double i,double j,double k);
    Vector dotProduct(Vector& c);
    Vector crossProduct(Vector& c);
    Vector operator+(Vector& c);
    Vector operator-(Vector& c);
    friend istream& operator>>(istream& cin, Vector& m);
    friend ostream& operator<<(ostream& cout, Vector& m);

};
#endif
