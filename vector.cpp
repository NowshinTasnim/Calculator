#include "common.h"
#include "vector.h"

Vector::Vector()
{
    i=0;
    j=0;
    k=0;
}

Vector::Vector(double i,double j,double k)
{
    this->i=i;
    this->j=j;
    this->k=k;
}
Vector::Vector(Vector& v)
{
    this->i=v.i;
    this->j=v.j;
    this->k=v.k;

}
Vector::geti()
{
    return i;
}
Vector::getj()
{
    return j;
}
Vector::getk()
{
    return k;
}
Vector::setdata(double i,double j,double k)
{
    this->i=i;
    this->j=j;
    this->k=k;
}
Vector Vector::dotProduct(Vector& c)
{
    Vector temp;
    temp.i=i*c.i;
    temp.j=j*c.j;
    temp.k=k*c.k;
    return temp;
}
Vector Vector::crossProduct(Vector& c)
{
    Vector temp;
    temp.i=j*c.k-k*c.j;
    temp.j=i*c.k-k*c.i;
    temp.k=i*c.j-j*c.i;
    return temp;
}
Vector Vector::operator+(Vector& c)
{
    Vector temp;
    temp.i=i+c.i;
    temp.j=j+c.j;
    temp.k=k+c.k;
    return temp;
}
Vector Vector::operator-(Vector& c)
{
    Vector temp;
    temp.i=i-c.i;
    temp.j=j-c.j;
    temp.k=k-c.k;
    return temp;
}
istream& operator>>(istream& cin, Vector& m)
{
    cout<<"\t\tEnter i: ";
    cin>>m.i;
    clean();
    cout<<"\t\tEnter j: ";
    cin>>m.j;
    clean();
    cout<<"\t\tEnter k: ";
    cin>>m.k;
    clean();
}
ostream& operator<<(ostream& cout, Vector& m)
{
    cout<<"\t\t"<<m.i<<"i+"<<m.j<<"j+"<<m.k<<"k";
}
