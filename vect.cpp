#include "common.h"
#include "vector.h"

void vect()
{
    Vector A,B,ANS;
    double i,j,k;
    int vm=-1,flagA=0,flagB=0,flagAns=0;
    while(true)
    {
        if(vm==8)
        {
            choice=-1;
            break;
        }
        else if(vm==-1)
        {
            system("CLS");
            cout<<"\n\n\t\tVECTOR MENU"<<endl;
            cout<<"\t\t1.Vec A 2.Vec B 3.Vec ANS 4.ADD \n\t\t5.SUB 6.DOT PRODUCT 7.CROSS PRODUCT 8.Menu\n\t\tChoose your option: ";
            cin>>vm;
            clean();
        }
        else if(vm==1)
        {
            if(flagA==0)
            {
                system("CLS");
                cout<< "\n\n\t\tVec A "<<endl;
                cout<<"\t\tEnter i: ";
                cin>>i;
                clean();
                cout<<"\t\tEnter j: ";
                cin>>j;
                clean();
                cout<<"\t\tEnter k: ";
                cin>>k;
                clean();
                A.setdata(i,j,k);
                flagA=1;
            }
            else if(flagA==1)
            {
                cout<<"\t\tVec A:"<<endl;
                cout<<A<<endl;
                flagA=2;
            }
            else if(flagA==2)
            {
                char change;
                cout<<"\n\n\t\tDo you want to change?(Y/N): ";
                cin>>change;
                if(change=='Y' ||change=='y')
                {
                    flagA=0;
                }
                else if(change=='N' ||change=='n')
                {
                    flagA=1;
                    vm=-1;
                }
                else
                {
                    flagA=2;
                }
            }
        }
        else if(vm==2)
        {
            if(flagB==0)
            {
                system("CLS");
                cout<<"\n\n\t\tVec B:"<<endl;
                cin>>B;
                flagB=1;
            }
            else if(flagB==1)
            {
                cout<<"\t\tVec B:"<<endl;
                cout<<B<<endl;
                flagB=2;
            }
            else if(flagB==2)
            {
                char change;
                cout<<"\n\n\t\tDo you want to change?(Y/N): ";
                cin>>change;
                if(change=='Y' ||change=='y')
                {
                    flagB=0;
                }
                else if(change=='N' ||change=='n')
                {
                    flagB=1;
                    vm=-1;
                }
                else
                {
                    flagB=2;
                }
            }
        }
        else if(vm==3)
        {
            system("CLS");
            if(flagAns==1)
            {
                cout<<"\n\n\t\tVec ANS: "<<endl;
                cout<<ANS<<endl;
            }
            else
            {
                cout<<"\n\n\t\tnothing is stored"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO VECTOR MENU: ";
            getline(cin,dummy);
            vm=-1;
        }
        else if(vm==4)
        {
            system("CLS");
            if(flagA==1 && flagB==1)
            {
                cout<<"\n\n\t\tADDITION RESULT:"<<endl;
                Vector d(A);
                Vector e(B);
                ANS=d+e;
                flagAns=1;
                cout<<ANS<<endl;
            }
            else
            {
                cout<<"\n\n\t\tVector is not given"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO VECTOR MENU: ";
            getline(cin,dummy);
            vm=-1;
        }
        else if(vm==5)
        {
            system("CLS");
            if(flagA==1 && flagB==1)
            {
                cout<<"\n\n\t\tSUB RESULT:"<<endl;
                ANS=A-B;
                flagAns=1;
                cout<<ANS<<endl;
            }
            else
            {
                cout<<"\n\n\t\tVector is not given"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO VECTOR MENU: ";
            getline(cin,dummy);
            vm=-1;
        }
        else if(vm==6)
        {
            system("CLS");
            if(flagA==1 && flagB==1)
            {
                cout<<"\n\n\t\tDOT PRODUCT RESULT:"<<endl;
                ANS=A.dotProduct(B);
                flagAns=1;
                cout<<ANS<<endl;
            }
            else
            {
                cout<<"\n\n\t\tVector is not given"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO VECTOR MENU: ";
            getline(cin,dummy);
            vm=-1;
        }
        else if(vm==7)
        {
            system("CLS");
            if(flagA==1 && flagB==1)
            {
                cout<<"\n\n\t\tCROSS PRODUCT RESULT:"<<endl;
                ANS=A.crossProduct(B);
                flagAns=1;
                cout<<ANS<<endl;
            }
            else
            {
                cout<<"\n\n\t\tVector is not given"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO VECTOR MENU: ";
            getline(cin,dummy);
            vm=-1;
        }
        else
        {
            vm=-1;
        }
    }
}
