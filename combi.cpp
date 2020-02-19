#include "common.h"
#include "combinatorix.h"

ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nCr(ll n,ll r)
{
    if(r==0 || r==n)
        return 1;
    return nCr(n-1,r-1)+nCr(n-1,r);
}

ll nPr(ll n,ll r)
{
    return nCr(n,r)*fact(r);
}
void combi()
{
    ll cmb=-1,n,r;
    Combin *ptr;
    while(true)
    {
        if(cmb==3)
        {
            choice=-1;
            break;
        }
        else if(cmb==-1)
        {
            system("CLS");
            cout<<"\n\n\t\tCOMBINATORICS MENU"<<endl;
            cout<<"\t\t1.nCr 2.nPr 3.Return to menu\n\t\tChoose your option: ";
            cin>>cmb;
            clean();
        }
        else if(cmb==1)
        {
            system("CLS");
            cout<<"\n\n\t\tEnter the value of n and r: ";
            cin>>n>>r;
            clean();
            Ncr ob1(nCr(n,r),n,r);
            ptr=&ob1;
            ptr->getter();
            string dummy;
            cout<<"\t\tENTER ANY KEY TO GO TO COMBINATORICS MENU: ";
            getline(cin,dummy);
            cmb=-1;
        }
        else if(cmb==2)
        {
            system("CLS");
            cout<<"\n\n\t\tEnter the value of n and r: ";
            cin>>n>>r;
            clean();
            Npr ob2(nPr(n,r),n,r);
            ptr=&ob2;
            ptr->getter();
            string dummy;
            cout<<"\t\tENTER ANY KEY TO GO TO COMBINATORICS MENU: ";
            getline(cin,dummy);
            cmb=-1;
        }
    }

}
