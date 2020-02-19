#include "main.h"
int choice=-1;

int main()
{
    int option=0;
    while(true)
    {
        if(choice==3)
        {
            exit();
            break;
        }
        else if(choice==-1)
        {
            menu();
        }
        else if(choice==1)
        {
            system("CLS");
            cout<<"\n\n\t\tMODE MENU"<<endl;
            cout<<"\t\t1.Statistics 2.Matrix 3.Vector 4.Complex \n\t\t5.Combinatorics 6.Base conversion 7.Return to menu\n\t\tChoose your option: ";
            cin>>option;
            clean();
            if(option==1)
            {
                stat();
            }
            else if(option==2)
            {
                mat();
            }
            else if(option==3)
            {
                vect();
            }
            else if(option==4)
            {
                comp();
            }
            else if(option==5)
            {
                combi();
            }
            else if(option==6)
            {
                base();
            }
            else if(option==7)
            {
                choice=-1;
            }
            else choice=1;
        }
        else if(choice==2)
        {
            norm();
        }
        else choice=-1;
    }
    return 0;
}
