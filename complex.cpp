#include "complex.h"
#include "common.h"
Complex::Complex()
{
    real=0;
    img=0;
}

Complex::Complex(Complex &obj)
{
    this->real=obj.real;
    this->img=obj.img;
}

double Complex:: getComp()
{
    cout<<"\t\t"<<real<<"+i"<<img<<endl;
}

void Complex:: setComp(double real,double img)
{
    this->real=real;
    this->img=img;
}

Complex Complex::operator+(Complex& c)
{
    Complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
}

Complex Complex::operator-(Complex& c)
{
    Complex temp;
    temp.real = real - c.real;
    temp.img = img - c.img;
    return temp;
}

Complex Complex::operator*(Complex& c)
{
    Complex temp;
    temp.real = (real*c.real)-(img*c.img);
    temp.img =(real*c.img)+ (img* c.real);
    return temp;
}

Complex Complex::operator*(int num)
{
    Complex temp;
    temp.real = real*num;
    temp.img = img*num;
    return temp;
}
