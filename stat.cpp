#include "common.h"
#include"statistic.h"

void stat()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout<<setprecision(2)<<setiosflags(ios::fixed);
    cout<<setprecision(2)<<setiosflags(ios::fixed);
    int sm,n=0;
    string line;
    string dummy;
    vector<Data> datas;
    double mival,maval,freq,xi,avg;
    fin>>line>>line;
    while(fin>>mival>>dummy>>maval>>freq)
    {
        xi=(mival+maval)/2;
        Data data(mival, maval, freq,xi,freq*xi);
        //double d=data.getfixi();
        n++;
        datas.push_back(data);
    }
    sm=-1;
    while(true)
    {
        if(sm==3)
        {
            choice=-1;
            break;
        }
        else if(sm==-1)
        {
            system("CLS");
            cout<<"\n\n\t\tSTATISTIC MENU"<<endl;
            cout<<"\t\t1.Mean 2.Standard daviation 3.Menu\n\t\tChoose your option: ";
            cin>>sm;
            clean();
        }
        else if(sm==1)
        {
            system("CLS");
            fout<<"MEAN OF GIVEN DATA: ";
            double total=0;

            for(int i=0;i<n;i++)
            {
                total+=datas[i].getfixi();
            }
            avg=total/n;
            fout<<avg<<endl;
            mean::Mean obj;
            obj.setter(avg);
            obj.getter();
            string dummy2;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO STATISTIC MENU: ";
            getline(cin,dummy2);
            sm=-1;
        }
        else if(sm==2)
        {
            system("CLS");
            fout<<"STANDARD DAVIATION OF GIVEN DATA: ";
            double total=0,devsq,dev;
            for(int i=0;i<n;i++)
            {
                total+=(pow((datas[i].getxi()-avg),2))*datas[i].getfreq();
            }
            devsq=total/n;
            dev=sqrt(devsq);
            fout<<dev<<endl;
            standard::Sd obj;
            obj.setter(dev);
            obj.getter();
            string dummy2;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO STATISTIC MENU: ";
            getline(cin,dummy2);
            sm=-1;
        }
        else
        {
            sm=-1;
        }
    }
    fout.close();
    fin.close();
}

