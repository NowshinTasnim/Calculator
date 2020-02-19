#ifndef COMBINATORIX_H
#define COMBINATORIX_H
#include "common.h"

class Combin
{
protected:
    ll n,r;
public:
    Combin(ll n,ll r)
    {
        this->n=n;
        this->r=r;
    }
    virtual void getter(){};
};

class Ncr:public Combin
{
    ll res;
public:
    Ncr(ll res,ll n,ll r):Combin(n,r)
    {
        this->res=res;
    }
    void getter()
    {
        cout<<"\t\tValue of "<<n<<"C"<<r<<" is: "<<res<<endl;
    }
};

class Npr:public Combin
{
    ll res;
public:
    Npr(ll res,ll n,ll r):Combin(n,r)
    {
        this->res=res;
    }
    void getter()
    {
        cout<<"\t\tValue of "<<n<<"P"<<r<<" is: "<<res<<endl;
    }
};
#endif


