#include "common.h"
#include "complex.h"

void comp()
{
    Complex A,B,ANS;
    double real,img;
    int cm=-1,flagcA=0,flagcB=0,flagcAns=0;
    cout<<setprecision(2)<<setiosflags(ios::fixed);
    while(true)
    {
        //<<menu
        if(cm==8)
        {
            choice=-1;
            return;
        }
        //<<COMPLEX MENU>>
        else if(cm==-1)
        {
            system("CLS");
            cout<<"\n\n\t\tCOMPLEX MENU"<<endl;
            cout<<"\t\t1.Comp A 2.Comp B 3.Comp ANS 4.ADD \n\t\t5.SUB 6.Scaler MUL 7.Complex MUL 8.Menu\n\t\tChoose your option: ";
            cin>>cm;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    //<< COMPLEX A>>
        else if(cm==1)
        {
            if(flagcA==0)
            {
                system("CLS");
                cout<<"\n\n\t\tCOMPLEX A"<<endl;
                cout<<"\t\tEnter real part: ";
                cin>>real;
                clean();
                cout<<"\t\tEnter imaginary part: ";
                cin>>img;
                clean();
                A.setComp(real,img);
                flagcA=1;
            }
            else if(flagcA==1)
            {
                system("CLS");
                cout<<"\n\n\t\tCOMPLEX A"<<endl;
                A.getComp();
                flagcA=2;
            }
            else if(flagcA==2)
            {
                char change;
                cout<<"\t\tDo you want to change this?(Y/N): ";
                cin>>change;
                if(change=='Y' || change=='y')
                {
                    flagcA=0;
                }
                else if(change=='N' ||change=='n')
                {
                    flagcA=1;
                    cm=-1;
                }
                else
                {
                    flagcA=2;
                }
            }
        }
    //<<<COMPLEX B>>
        else if(cm==2)
        {
            if(flagcB==0)
            {
                system("CLS");
                cout<<"\n\n\t\tCOMPLEX B"<<endl;
                cout<<"\t\tEnter real part: ";
                cin>>real;
                clean();
                cout<<"\t\tEnter imaginary part: ";
                cin>>img;
                clean();
                B.setComp(real,img);
                flagcB=1;
            }
            else if(flagcB==1)
            {
                system("CLS");
                cout<<"\n\n\t\tCOMPLEX B"<<endl;
                B.getComp();
                flagcB=2;
            }
            else if(flagcB==2)
            {
                char change;
                cout<<"\t\tDo you want to change this?(Y/N): ";
                cin>>change;
                if(change=='Y'||change=='y')
                {
                    flagcB=0;
                }
                else if(change=='N'||change=='n')
                {
                    flagcB=1;
                    cm=-1;
                }
                else
                {
                    flagcB=2;
                }
            }
        }
    //<<COMPLEX ANS
        else if(cm==3)
        {
            system("CLS");
            if(flagcAns==1)
            {
                cout<<"\n\n\t\tCOMPLEX ANS"<<endl;
                ANS.getComp();
            }
            else
            {
                cout<<"\n\n\t\tnothing is stored"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO COMPLEX MENU: ";
            getline(cin,dummy);
            cm=-1;
        }
    //<<ADD>>
        else if(cm==4)
        {
            system("CLS");
            if(flagcA==1 && flagcB==1)
            {
                cout<<"\n\n\t\tADDITION RESULT:"<<endl;
                Complex d(A);
                Complex e(B);
                ANS = d+e;
                flagcAns=1;
                ANS.getComp();
            }
            else
            {
                cout<<"\n\n\t\tInvalid input"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO COMPLEX MENU: ";
            getline(cin,dummy);
            cm=-1;
        }
    //<<SUB>>
        else if(cm==5)
        {
            system("CLS");
            if(flagcA==1 && flagcB==1)
            {
                cout<<"\n\n\t\tSUB RESULT:"<<endl;
                Complex d(A);
                Complex e(B);
                ANS=d-e;
                flagcAns=1;
                ANS.getComp();
            }
            else
            {
                cout<<"\n\n\t\tInvalid input"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO COMPLEX MENU: ";
            getline(cin,dummy);
            cm=-1;
        }
    //<<scaler Mul>>
        else if(cm==6)
        {
            system("CLS");
            int num,c;
            cout<<"\n\n\t\tEnter the real number u want to multiply : ";
            cin>>num;
            clean();
            cout<<"\t\tMultiply with 1.COMP A 2.COMP B\n\t\tChoose your option: ";
            cin>>c;
            clean();
            cout<<"\t\tscaler MUL RESULT:"<<endl;
            if(c==1 && flagcA==1)
            {
                ANS=A*num;
                flagcAns=1;
                ANS.getComp();
            }
            else if(c==2 && flagcB==1)
            {
                ANS=A*num;
                flagcAns=1;
                ANS.getComp();
            }
            else
            {
                cout<<"\t\twrong input or invalid complex number!"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO COMPLEX MENU: ";
            getline(cin,dummy);
            cm=-1;
        }
    //<<complex Mul>>
        else if(cm==7)
        {
            system("CLS");
            if(flagcA==1 && flagcB==1)
            {
                cout<<"\n\n\t\tCOMPLEX MUL RESULT:"<<endl;
                Complex d(A);
                Complex e(B);
                ANS=d*e;
                flagcAns=1;
                ANS.getComp();
            }
            else
            {
                cout<<"\n\n\t\tInvalid input"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO COMPLEX MENU: ";
            getline(cin,dummy);
            cm=-1;
        }
        else
        {
            cm=-1;
        }
    }
}
