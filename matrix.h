#ifndef MATRIX_H
#define MATRIX_H
#include "common.h"

class Matrix
{
    double **data;
    int row;
    int col;
public:
    Matrix();
    Matrix(int r,int c);
    void setMat(int row,int col);
    void setrc(int row,int col);
    double getMat(int i,int j);
    int getrow();
    void copyMat(Matrix obj);
    int getcol();
    void setter(int i,int j,double num);
    int getOrder();
    bool square();
    ~Matrix();
    Matrix operator +( Matrix& obj);
    Matrix operator -( Matrix& obj);
    Matrix operator *( Matrix& obj);
    Matrix operator *(double num);
    Matrix operator /(double num);
    friend istream& operator>>(istream& cin, Matrix& m);
    friend ostream& operator<<(ostream& cout, Matrix& m);
};

#endif
