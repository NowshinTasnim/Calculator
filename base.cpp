#include "common.h"
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

ll toDeci(char *str, int base)
{
    ll len = strlen(str);
    ll power = 1;
    ll num = 0;
    ll i;
    for (i = len - 1; i >= 0; i--)
    {
        if (val(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    strev(res);
    return res;
}

void base()
{
    ll bm=-1,base,num;
    char str[100];
    while(true)
    {
        if(bm==3)
        {
            choice=-1;
            break;
        }
        else if(bm==-1)
        {
            system("CLS");
            cout<<"\n\n\t\tCBASE CONVERSION MENU"<<endl;
            cout<<"\t\t1.To DEC 2.DEC to others 3.Return to menu\n\t\tChoose your option: ";
            cin>>bm;
            clean();
        }
        else if(bm==1)
        {
            system("CLS");
            cout<<"\n\n\t\tInput the number(0-F): ";
            cin>>str;
            clean();
            cout<<"\t\tBase of the number: ";
            cin>>base;
            clean();
            cout<<"\t\tDecimal equivalent of "<<str<<" in base "<<base<<" is: "<<toDeci(str, base)<<endl;
            string dummy;
            cout<<"\t\tENTER ANY KEY TO GO TO BASE CONVERSION MENU: ";
            getline(cin,dummy);
            bm=-1;
        }
        else if(bm==2)
        {
            system("CLS");
            cout<<"\n\n\t\tInput the number(decimal): ";
            cin>>num;
            clean();
            cout<<"\t\tConvert to Base : ";
            cin>>base;
            clean();
            string dummy;
            cout<<"\t\tENTER ANY KEY TO GO TO BASE CONVERSION MENU: ";
            getline(cin,dummy);
            bm=-1;
        }
    }
}
