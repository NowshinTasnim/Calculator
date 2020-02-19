#include "common.h"
ttt
T add(T x,T y)
{
    return x+y;
}
ttt
T sub(T x,T y)
{
    return x-y;
}
ttt
T mul(T x,T y)
{
    return x*y;
}
//functor
class Div
{
    double num;
public:
    Div(double n):num(n){}
    double operator()(double m)
    {
        return num/m;
    }

};
ttt
T div(T x,T y)
{
    return x/y;
}
ttt
T mod(T x,T y)
{
    return x%y;
}
void norm()
{
    char operation;
    double in1,in2,ans,nm=-1;
    while(true)
    {
        if(nm==2)
        {
            choice=-1;
            return;
        }
        else if(nm==-1)
        {
            system("CLS");
            cout<<"\n\n\t\tNORMAL CALCULATION MENU"<<endl;
            cout<<"\t\t1.Calculate 2.Menu\n\t\tChoose your option: ";
            cin>>nm;
            clean();
        }
        else if(nm==1)
        {
            system("CLS");
            cout<<"\n\n\t\tChoose operation(+,-,*,/,%,^,#(sqrt)):";
            cin>>operation;
            clean();
            cout<<"\t\tInput 1: ";
            cin>>in1;
            clean();
            if(operation!='#')
            {
                cout<<"\t\tInput 2: ";
                cin>>in2;
                clean();
            }
            cout<<setprecision(3)<<setiosflags(ios::fixed);
            if(operation=='+')
            {
                ans=add<double>(in1,in2);
                cout<<"\t\t"<<ans<<endl;
            }
            else if(operation=='-')
            {
                ans=sub<double>(in1,in2);
                cout<<"\t\t"<<ans<<endl;
            }
            else if(operation=='*')
            {
                ans=mul<double>(in1,in2);
                cout<<"\t\t"<<ans<<endl;
            }
            else if(operation=='/')
            {
                Div x(in1);
                ans= x(in2);
                cout<<"\t\t"<<ans<<endl;
            }
            else if(operation=='%')
            {
                ans=mod<ll>(in1,in2);
                cout<<"\t\t"<<ans<<endl;
            }
            else if(operation=='^')
            {
                ans=pow(in1,in2);
                cout<<"\t\t"<<ans<<endl;
            }
            else if(operation=='#')
            {
                ans=sqrt(in1);
                cout<<"\t\t"<<ans<<endl;
            }
            if(nm!=-1)
            {
              string dummy;
              cout<<"\t\tEnter any char to go to normal mode: ";
              getline(cin,dummy);
              nm=-1;
            }

        }
        else
        {
            nm=-1;
        }
    }
}
