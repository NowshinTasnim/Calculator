#include "common.h"
#include "matrix.h"

Matrix::Matrix()
{
    row=0;
    col=0;
    data=new double *[row];
    for(int i=0;i<row;i++)
        data[i]= new double[col];
}
void Matrix:: copyMat(Matrix obj)
{
    this->row=obj.row;
    this->col=obj.col;
    data=new double *[row];
    for(int i=0;i<row;i++)
        data[i]=new double[col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            data[i][j]=obj.data[i][j];
        }
    }
}

Matrix::Matrix(int r,int c)
{
    row=r;
    col=c;
    data=new double*[row];
    for(int i=0;i<row;i++)
        data[i]= new double[col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
                data[i][j]=0;
}

void Matrix::setMat(int row,int col)
{
    for(int i=0;i<this->row;i++)
        delete [] data[i];
    delete []data;
    this->row=row;
    this->col=col;
    data=new double*[row];
    for(int i=0;i<row;i++)
        data[i]= new double[col];
    for(int i=0; i<this->row; i++)
        for(int j=0; j<this->col; j++)
            cin>>data[i][j];
}

void Matrix::setrc(int row,int col)
{
    this->row=row;
    this->col=col;
    data=new double*[row];
    for(int i=0;i<row;i++)
        data[i]= new double[col];
}

int Matrix::getrow()
{
    return this->row;
}

int Matrix::getcol()
{
    return this->col;
}

double Matrix::getMat(int i,int j)
{
    return data[i][j];

}
void Matrix::setter(int i,int j,double num)
{
    data[i][j]=num;
}
int Matrix::getOrder()
{
    return this->row;
}
bool Matrix::square()
{
    if(this->row==this->col)
        return true;
    else return false;
}

Matrix::~Matrix()
{
    for(int i=0;i<this->row;i++)
        delete [] data[i];
    delete []data;
}

Matrix Matrix::operator +(Matrix& obj)
{
    Matrix m(this->row, this->col);
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->col;j++)
            m.data[i][j]=data[i][j]+ obj.data[i][j];
    return m;
}

Matrix Matrix::operator -(Matrix& obj)
{
    Matrix m(this->row, this->col);
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->col;j++)
            m.data[i][j]=data[i][j]-obj.data[i][j];
    return m;
}

Matrix Matrix::operator *(Matrix& obj)
{
    int i,j,k;
    Matrix m(this->row, this->col);
    m.row=row;
    m.col=obj.col;
    for(i=0;i<row;i++)
        for(j=0;j<obj.col;j++)
            for(k=0;k<col;k++)
                m.data[i][j]=(data[i][k]*obj.data[k][j]);
    return m;
}

Matrix Matrix:: operator *(double num)
{
    Matrix m(this->row, this->col);
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->col;j++)
            m.data[i][j]=data[i][j]*num;
    return m;
}

Matrix Matrix:: operator /(double num)
{
    Matrix m(this->row, this->col);
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->col;j++)
            m.data[i][j]=data[i][j]/num;
    return m;
}

istream& operator>>(istream& cin, Matrix& m)
{
    for(int i=0; i<m.row; i++)
        for(int j=0; j<m.col; j++)
            cin>>m.data[i][j];
    clean();
    return cin;
}

ostream& operator<<(ostream& cout, Matrix& m)
{
    for(int i=0; i<m.row; i++)
    {
        cout<<"\t\t";
        for(int j=0; j<m.col; j++)
            cout<<m.data[i][j]<<" ";
        cout<<endl;
    }
    return cout;
}
