#include "common.h"
#include "matrix.h"


void getCofactor(double **vec,double **temp,int p,int q,int n)
{
    int i=0,j=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(row!=p && col!=q)
            {
                temp[i][j++]= vec[row][col];
                if(j==n-1)
                {
                    j=0;
                    i++;
                }
            }
        }
    }
}
double determinant(double **vec,int n)
{
    double D=0;
    if(n==1) return vec[0][0];
    double **temp;
    temp=new double*[n];
    for(int k=0;k<n;k++)
        temp[k]=new double[n];
    int sign=1;
    for(int i=0;i<n;i++)
    {
        getCofactor(vec,temp,0,i,n);
        D+= sign*vec[0][i]*determinant(temp,n-1);
        sign= -sign;
    }
    for(int i=0;i<n;i++)
        delete [] temp[i];
    delete [] temp;
    return D;
}

double ** adjoint(double **A,double **adj,int n)
{
    if (n == 1)
    {
        adj[0][0] = 1;
        return adj;
    }
    int sign = 1;
    double **temp;
    temp=new double *[n];
    for(int i=0;i<n;i++)
        temp[i]=new double[n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            getCofactor(A, temp, i, j, n);
            sign = ((i+j)%2==0)? 1: -1;
            adj[j][i] = (sign)*(determinant(temp, n-1));
        }
    }
    for(int i=0;i<n;i++)
        delete [] temp[i];
    delete [] temp;
    return adj;
}

double ** inverse(double **A, double **inv,int n)
{
    double det = determinant(A, n);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return inv;
    }
    double **adjans,**adj;
    adj=new double *[n];
    for(int i=0;i<n;i++)
        adj[i]=new double[n];
    adjans=new double *[n];
    for(int i=0;i<n;i++)
        adjans[i]=new double[n];
    adjans=adjoint(A, adj,n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            inv[i][j] = adjans[i][j]/det;
    for(int i=0;i<n;i++)
        delete [] adj[i];
    delete[] adj;
    for(int i=0;i<n;i++)
        delete [] adjans[i];
    delete[] adjans;
    return inv;
}

double ** transpose(double **vec,int n)
{
    double **trans;
    trans=new double *[n];
    for(int i=0;i<n;i++)
        trans[i]=new double[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            trans[j][i]=vec[i][j];
    return trans;
}

void mat()
{
    Matrix A,B,C,ANS;
    int r,c,mm=-1,flagA=0,flagB=0,flagC=0,flagAns=0;
    cout<<setprecision(2)<<setiosflags(ios::fixed);
    while(true)
    {
        //<<<<<FOR MENU>>
        if(mm==13)
        {
            choice=-1;
            return;
        }
        //<<<FOR MATRIX MENU>>
        else if(mm==-1)
        {
            system("CLS");
            cout<<"\n\n\t\tMATRIX MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.DET 6.ADD\n\t\t7. MUL 8.SUB 9.ADJ 10.Inverse 11.Transpose 12.DIV \n\t\t13.Menu\n\t\tChoose your option: ";
            cin>>mm;
            clean();
        }
    // <<<FOR MAT A>>>
        else if(mm==1)
        {
            if(flagA==0)
            {
                system("CLS");
                cout<<"\n\n\t\tMATRIX A:"<<endl;
                cout<<"\t\tDimension: \n\t\tENTER THE DIM OF ROW: ";
                cin>>r;
                clean();
                cout<<"\t\tENTER THE DIM OF COLUMN: ";
                cin>>c;
                clean();
                cout<<"\t\tEnter the value of the index: ";
                A.setMat(r,c);
                flagA=1;
            }
            else if(flagA==1)
            {
                cout<<"\t\tMATRIX A:"<<endl;
                cout<<A;
                flagA=2;
            }
            else if(flagA==2)
            {
               char change;
                cout<<"\t\tDo you want to change this?(Y/N): ";
                cin>>change;
                if(change=='Y'|| change=='y')
                {
                    flagA=0;
                }
                else if(change=='N'||change=='n')
                {
                    flagA=1;
                    mm=-1;
                }
                else
                {
                    flagA=2;
                }
            }
        }
    // <<<FOR MAT B>>>
        else if(mm==2)
        {
            if(flagB==0)
            {
                system("CLS");
                cout<<"\n\n\t\tMATRIX B:"<<endl;
                cout<<"\t\tDimension:\n\t\tENTER THE DIM OF ROW: ";
                cin>>r;
                clean();
                cout<<"\t\tENTER THE DIM OF COLUMN: ";
                cin>>c;
                clean();
                cout<<"\t\tEnter the value of the index: ";
                B.setMat(r,c);
                flagB=1;
            }
            else if(flagB==1)
            {
                cout<<"\t\tMATRIX B:"<<endl;
                cout<<B;
                flagB=2;
            }
            else if(flagB==2)
            {
                char change;
                cout<<"\t\tDo you want to change this?(Y/N): ";
                cin>>change;
                if(change=='Y'|| change=='y')
                {
                    flagB=0;
                }
                else if(change=='N'||change=='n')
                {
                    flagB=1;
                    mm=-1;
                }
                else
                {
                    flagB=2;
                }
            }
        }
    // <<<FOR MAT C>>>
        else if(mm==3)
        {
            if(flagC==0)
            {
                system("CLS");
                cout<<"\n\n\t\tMATRIX C:"<<endl;
                cout<<"\t\tDimension:\n\t\tENTER THE DIM OF ROW: ";
                cin>>r;
                clean();
                cout<<"\t\tENTER THE DIM OF COLUMN: ";
                cin>>c;
                clean();
                cout<<"\t\tEnter the value of the index: ";
                C.setMat(r,c);
                flagC=1;
            }
            else if(flagC==1)
            {
                cout<<"\t\tMATRIX C:"<<endl;
                cout<<C;
                flagC=2;
            }
            else if(flagC==2)
            {
               char change;
                cout<<"\t\tDo you want to change this?(Y/N): ";
                cin>>change;
                if(change=='Y'|| change=='y')
                {
                    flagC=0;
                }
                else if(change=='N'||change=='n')
                {
                    flagC=1;
                    mm=-1;
                }
                else
                {
                    flagC=2;
                }
            }
        }
    // <<<FOR MAT ANS>>>
        else if(mm==4)
        {
            system("CLS");
            if(flagAns==1)
            {
                cout<<"\n\n\t\tMATRIX ANS:";
                cout<<ANS;
            }
            else
            {
                cout<<"\n\n\t\tnothing is stored"<<endl;
            }
            string dummy;
            cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO MATRIX MENU: ";
            getline(cin,dummy);
            mm=-1;
        }
    // <<<FOR DET>>>
        else if(mm==5)
        {
            system("CLS");
            int mmm;
            cout<<"\n\n\t\tDET MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu\n\t\tChoose your option: ";
            cin>>mmm;
            clean();
            Matrix obj;
            if(mmm==1 && flagA==1)
            {
                obj.setrc(A.getrow(),A.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,A.getMat(i,j));
            }
            else if(mmm==2 && flagB==1)
            {
                obj.setrc(B.getrow(),B.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,B.getMat(i,j));
            }
            else if(mmm==3 &&flagC==1)
            {
                obj.setrc(C.getrow(),C.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,C.getMat(i,j));
            }
            else if(mmm==4 && flagAns==1)
            {
                obj.setrc(ANS.getrow(),ANS.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,ANS.getMat(i,j));
            }
            else if(mmm==5)
            {
                mm=-1;
            }
            else
            {
                cout<< "\t\tthe matrix is not given or you pressed the wrong button";
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO MUL MENU: ";
                getline(cin,dummy);
                mm=5;
            }
            if(mm!=-1)
            {
                double **vec;
                if(obj.square())
                {
                    int n=obj.getOrder();
                    vec= new double*[n];
                    for(int i=0;i<n;i++)
                        vec[i]= new double[n];
                    for(int i=0;i<n;i++)
                        for(int j=0;j<n;j++)
                            vec[i][j]=obj.getMat(i,j);
                    double ans=determinant(vec,n);
                    cout<<"\t\t"<<ans<<endl;
                    for(int i=0;i<n;i++)
                        delete [] vec[i];
                    delete [] vec;
                }
                else
                {
                    cout<<"\t\tDim error!!"<<endl;
                }
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO DET MENU: ";
                getline(cin,dummy);
                mm=5;
            }
        }
    //<<<<FOR ADD>>
        else if (mm==6)
        {
            system("CLS");
            int first,second;
            cout<<"\n\n\t\tADD MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu(enter 5 5 for it)\n\t\tChoose any two option: ";
            cin>>first>>second;
            clean();
            if(((first==1 && second ==2)||(first==2 && second ==1))&& flagA==1 && flagB==1)
            {
                if(A.getrow()==B.getrow() && A.getcol()==B.getcol())
                {
                    ANS.copyMat(A+B);
                    flagAns=1;
                    cout<<"\t\tADDITION RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(((first==1 && second==3)||(first==3 && second ==1))&& flagA==1 && flagC==1)
            {
                if(A.getrow()==C.getrow() && A.getcol()==C.getcol())
                {
                    ANS.copyMat(A+C);
                    flagAns=1;
                    cout<<"\t\tADDITION RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(((first==1 && second==4)||(first==4 && second ==1))&& flagA==1 && flagAns==1)
            {
                if(A.getrow()==ANS.getrow() && A.getcol()==ANS.getcol())
                {
                    ANS.copyMat(ANS+A);
                    cout<<"\t\tADDITION RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(((first==2 && second==3)||(first==3 && second ==2))&& flagC==1 && flagB==1)
            {
                if(C.getrow()==B.getrow() && C.getcol()==B.getcol())
                {
                    ANS.copyMat(B+C);
                    flagAns=1;
                    cout<<"\t\tADDITION RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(((first==2 && second==4)||(first==4 && second ==2))&& flagAns==1 && flagB==1)
            {
                if(ANS.getrow()==B.getrow() && ANS.getcol()==B.getcol())
                {
                    ANS.copyMat(ANS+B);
                    cout<<"\t\tADDITION RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(((first==3 && second==4)||(first==4 && second ==3))&& flagA==1 && flagB==1)
            {
                if(ANS.getrow()==C.getrow() && ANS.getcol()==C.getcol())
                {
                    ANS.copyMat(ANS+C);
                    cout<<"\t\tADDITION RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==5 && second==5)
            {
                mm=-1;
            }
            else
            {
                cout<<"\t\tMatrix is not given or wrong input.Please Check!!" <<endl;
            }
            if(mm!=-1)
            {
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO ADD MENU: ";
                getline(cin,dummy);
                mm=6;
            }
        }
    //<<<<<<FOR MUL>>>>
        else if (mm==7)
        {
            system("CLS");
            int first,second,option;
            double num;
            cout<<"\n\n\t\tMUL MENU"<<endl;
            cout<<"\n\n\t\t1.Scaler 2.Matrix 3.Matrix menu\n\t\tChoose any option: ";
            cin>>option;
            clean();
            if(option==3)
            {
                mm=-1;
            }
            else if(option==1)
            {
                system("CLS");
                cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu\n\t\tChoose any option: ";
                cin>>first;
                clean();
                cout<<"Multiplied by:(input real number) ";
                cin>>num;
                clean();
                if(first==1)
                {
                    ANS.copyMat(A*num);
                    flagAns=1;
                    cout<<"\t\tMUL RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else if(first==2)
                {
                    ANS.copyMat(B*num);
                    flagAns=1;
                    cout<<"\t\tMUL RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else if(first==3)
                {
                    ANS.copyMat(C*num);
                    flagAns=1;
                    cout<<"\t\tMUL RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else if(first==4 && flagAns==1)
                {
                    ANS.copyMat(ANS*num);
                    cout<<"\t\tMUL RESULT:"<<endl;
                    cout<<ANS<<endl;
                }
                else if(first==5)
                {
                    mm=-1;
                }
                else
                {
                    cout<<"\t\tMatrix is not given or wrong input.Please Check!!" <<endl;
                }
            }
            else if(option==2)
            {
                system("CLS");
                cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu(5 5)\n\t\tChoose any two option: ";
                cin>>first>>second;
                clean();
                if((first==1 && second ==2)&& flagA==1 && flagB==1)
                {
                    if(A.getcol()==B.getrow())
                    {
                        ANS.copyMat(A*B);
                        flagAns=1;
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==2 && second ==1)&& flagA==1 && flagB==1)
                {
                    if(B.getcol()==A.getrow())
                    {
                        ANS.copyMat(B*A);
                        flagAns=1;
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==1 && second==3)&& flagA==1 && flagC==1)
                {
                    if(A.getcol()==C.getrow())
                    {
                        ANS.copyMat(A*C);
                        flagAns=1;
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==3 && second ==1)&& flagA==1 && flagC==1)
                {
                    if(C.getcol()==A.getrow())
                    {
                        ANS.copyMat(C*A);
                        flagAns=1;
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==1 && second==4)&& flagA==1 && flagAns==1)
                {
                    if(A.getcol()==ANS.getrow())
                    {
                        ANS.copyMat(A*ANS);
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==4 && second ==1)&& flagA==1 && flagAns==1)
                {
                    if(ANS.getcol()==A.getrow())
                    {
                        ANS.copyMat(ANS*A);
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==2 && second==3)&& flagC==1 && flagB==1)
                {
                    if(B.getcol()==C.getrow())
                    {
                        ANS.copyMat(B*C);
                        flagAns=1;
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==3 && second ==2)&& flagC==1 && flagB==1)
                {
                    if(C.getcol()==B.getrow())
                    {
                        ANS.copyMat(C*B);
                        flagAns=1;
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==2 && second==4)&& flagAns==1 && flagB==1)
                {
                    if(B.getcol()==ANS.getrow())
                    {
                        ANS.copyMat(B*ANS);
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==4 && second ==2 )&& flagAns==1 && flagB==1)
                {
                    if(ANS.getcol()==B.getrow())
                    {
                        ANS.copyMat(ANS*B);
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==3 && second==4)&& flagAns==1 && flagC==1)
                {
                    if(C.getcol()==ANS.getrow())
                    {
                        ANS.copyMat(C*ANS);
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if((first==4 && second ==3)&& flagAns==1 && flagC==1)
                {
                    if(ANS.getcol()==C.getrow())
                    {
                        ANS.copyMat(ANS*C);
                        cout<<ANS<<endl;
                    }
                    else
                    {
                        cout<<"\t\tDimension is not matched."<<endl;
                    }
                }
                else if(first==5 && second==5)
                {
                    mm=-1;
                }
                else
                {
                    cout<<"\t\tMatrix is not given or have choosen the wrong ans"<<endl;
                }
            }
            else
            {
                mm=7;
            }
            if(mm!=-1)
            {
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO MUL MENU: ";
                getline(cin,dummy);
                mm=7;
            }
        }
    //<<<FOR SUB>>>>
        else if (mm==8)
        {
            system("CLS");
            int first,second;
            cout<<"\n\n\t\tSUB MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu(5 5)\n\t\tChoose any two option: ";
            cin>>first>>second;
            clean();
            if(first==1 && second ==2 && flagA==1 && flagB==1)
            {
                if(A.getrow()==B.getrow() && A.getcol()==B.getcol())
                {
                    ANS.copyMat(A-B);
                    flagAns=1;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==2 && second ==1 && flagA==1 && flagB==1)
            {
                if(A.getrow()==B.getrow() && A.getcol()==B.getcol())
                {
                    ANS.copyMat(B-A);
                    flagAns=1;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==1 && second==3 && flagA==1 && flagC==1)
            {
                if(A.getrow()==C.getrow() && A.getcol()==C.getcol())
                {
                    ANS.copyMat(A-C);
                    flagAns=1;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==3 && second==1 && flagA==1 && flagC==1)
            {
                if(A.getrow()==C.getrow() && A.getcol()==C.getcol())
                {
                    ANS.copyMat(C-A);
                    flagAns=1;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==1 && second==4 && flagA==1 && flagAns==1)
            {
                if(A.getrow()==ANS.getrow() && A.getcol()==ANS.getcol())
                {
                    ANS.copyMat(A-ANS);
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==4 && second ==1 && flagA==1 && flagAns==1)
            {
                if(A.getrow()==ANS.getrow() && A.getcol()==ANS.getcol())
                {
                    ANS.copyMat(ANS-A);
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==2 && second==3 && flagC==1 && flagB==1)
            {
                if(C.getrow()==B.getrow() && C.getcol()==B.getcol())
                {
                    ANS.copyMat(B-C);
                    flagAns=1;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==3 && second ==2 && flagC==1 && flagB==1)
            {
                if(C.getrow()==B.getrow() && C.getcol()==B.getcol())
                {
                    ANS.copyMat(C-B);
                    flagAns=1;
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==2 && second==4 && flagAns==1 && flagB==1)
            {
                if(ANS.getrow()==B.getrow() && ANS.getcol()==B.getcol())
                {
                    ANS.copyMat(B-ANS);
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==4 && second ==2 && flagAns==1 && flagB==1)
            {
                if(ANS.getrow()==B.getrow() && ANS.getcol()==B.getcol())
                {
                    ANS.copyMat(ANS-B);
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==4 && second ==3 && flagAns==1 && flagC==1)
            {
                if(ANS.getrow()==C.getrow() && ANS.getcol()==C.getcol())
                {
                    ANS.copyMat(ANS-C);
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==3 && second==4 && flagAns==1 && flagC==1)
            {
                if(ANS.getrow()==C.getrow() && ANS.getcol()==C.getcol())
                {
                    ANS.copyMat(C-ANS);
                    cout<<ANS<<endl;
                }
                else
                {
                    cout<<"\t\tDimension is not matched."<<endl;
                }
            }
            else if(first==5 && second==5)
            {
                mm=-1;
            }
            else
            {
                cout<<"\t\tThe matrix is not given or wrong input"<<endl;
            }
            if(mm!=-1)
            {
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO SUB MENU: ";
                getline(cin,dummy);
                mm=8;
            }
        }
    //<<<<<FOR ADJ>>>>>
        else if(mm==9)
        {
            system("CLS");
            int mmm;
            cout<<"\n\t\tADJ MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu\n\t\tChoose your option: ";
            cin>>mmm;
            clean();
            Matrix obj;
            if(mmm==1 &&flagA==1)
            {
                obj.setrc(A.getrow(),A.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,A.getMat(i,j));
            }
            else if(mmm==2 && flagB==1)
            {
                obj.setrc(B.getrow(),B.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,B.getMat(i,j));
            }
            else if(mmm==3 && flagC==1)
            {
                obj.setrc(C.getrow(),C.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,C.getMat(i,j));
            }
            else if(mmm==4 && flagAns==1)
            {
                obj.setrc(ANS.getrow(),ANS.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,ANS.getMat(i,j));
            }
            else if(mmm==5)
            {
                mm=-1;
            }
            else
            {
                cout<<"\t\tthe matrix is not given or wrong input"<<endl;
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO ADJ MENU: ";
                getline(cin,dummy);
                mm=9;
            }
            if(mm!=-1)
            {
                double **vec;
                double **adj;
                double **ans;
                if(obj.square())
                {
                    int n=obj.getOrder();
                    vec= new double*[n];
                    for(int i=0;i<n;i++)
                        vec[i]= new double[n];
                    adj=new double *[n];
                    for(int i=0;i<n;i++)
                        adj[i]=new double[n];
                    for(int i=0;i<n;i++)
                        for(int j=0;j<n;j++)
                            vec[i][j]=obj.getMat(i,j);
                    ans=new double *[n];
                    for(int i=0;i<n;i++)
                        ans[i]=new double[n];
                    ans =adjoint(vec,adj,n);
                    for(int i=0;i<n;i++)
                    {
                        cout<<"\t\t";
                        for(int j=0;j<n;j++)
                            cout<<ans[i][j]<<' ';
                        cout<<endl;
                    }
                    for(int i=0;i<n;i++)
                        delete [] vec[i];
                    delete [] vec;
                    for(int i=0;i<n;i++)
                        delete [] adj[i];
                    delete [] adj;
                    for(int i=0;i<n;i++)
                        delete [] ans[i];
                    delete [] ans;
                }
                else
                {
                    cout<<"\t\tDim error!!"<<endl;
                }
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO ADJ MENU:";
                getline(cin,dummy);
                mm=9;
            }
        }
        //<<<<<FOR INV>>>>>
        else if(mm==10)
        {
            system("CLS");
            int mmm;
            cout<<"\n\n\t\tINV MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu\n\t\tChoose your option: ";
            cin>>mmm;
            clean();
            Matrix obj;
            if(mmm==1 &&flagA==1)
            {
                obj.setrc(A.getrow(),A.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,A.getMat(i,j));
            }
            else if(mmm==2 && flagB==1)
            {
                obj.setrc(B.getrow(),B.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,B.getMat(i,j));
            }
            else if(mmm==3 && flagC==1)
            {
                obj.setrc(C.getrow(),C.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,C.getMat(i,j));
            }
            else if(mmm==4 && flagAns==1)
            {
                obj.setrc(ANS.getrow(),ANS.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,ANS.getMat(i,j));
            }
            else if(mmm==5)
            {
                mm=-1;
            }
            else
            {
                cout<<"\t\tThe matrix is not given or wrong input"<<endl;
            }
            if(mm!=-1)
            {
                double **vec;
                double **inv;
                double **ans;
                if(obj.square())
                {
                    int n=obj.getOrder();
                    vec= new double*[n];
                    for(int i=0;i<n;i++)
                        vec[i]= new double[n];
                    inv=new double *[n];
                    for(int i=0;i<n;i++)
                        inv[i]=new double[n];
                    for(int i=0;i<n;i++)
                        for(int j=0;j<n;j++)
                            vec[i][j]=obj.getMat(i,j);
                    ans=new double *[n];
                    for(int i=0;i<n;i++)
                        ans[i]=new double[n];
                    ans =inverse(vec,inv,n);
                    for(int i=0;i<n;i++)
                    {
                        cout<<"\t\t";
                        for(int j=0;j<n;j++)
                            cout<<ans[i][j]<<' ';
                        cout<<endl;
                    }
                    for(int i=0;i<n;i++)
                        delete [] vec[i];
                    delete [] vec;
                    for(int i=0;i<n;i++)
                        delete [] inv[i];
                    delete [] inv;
                    for(int i=0;i<n;i++)
                        delete [] ans[i];
                    delete [] ans;
                }
                else
                {
                    cout<<"\t\tDim error!!"<<endl;
                }
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO ADJ MENU: ";
                getline(cin,dummy);
                mm=9;
            }
        }
        //<< FOR TRANSPOSE>>
        else if(mm==11)
        {
            system("CLS");
            int mmm;
            cout<<"\n\n\t\tTRANSPOSE MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu\nChoose your option: ";
            cin>>mmm;
            clean();
            Matrix obj;
            if(mmm==1 &&flagA==1)
            {
                obj.setrc(A.getrow(),A.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,A.getMat(i,j));
            }
            else if(mmm==2 && flagB==1)
            {
                obj.setrc(B.getrow(),B.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,B.getMat(i,j));
            }
            else if(mmm==3 && flagC==1)
            {
                obj.setrc(C.getrow(),C.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,C.getMat(i,j));
            }
            else if(mmm==4 && flagAns==1)
            {
                obj.setrc(ANS.getrow(),ANS.getcol());
                for(int i=0;i<obj.getrow();i++)
                    for(int j=0;j<obj.getcol();j++)
                        obj.setter(i,j,ANS.getMat(i,j));
            }
            else if(mmm==5)
            {
                mm=-1;
            }
            else
            {
                cout<<"\t\tThe matrix is not given or wrong input"<<endl;
            }
            if(mm!=-1)
            {
                double **vec;
                double **ans;
                if(obj.square())
                {
                    int n=obj.getOrder();
                    vec= new double*[n];
                    for(int i=0;i<n;i++)
                        vec[i]= new double[n];
                    for(int i=0;i<n;i++)
                        for(int j=0;j<n;j++)
                            vec[i][j]=obj.getMat(i,j);
                    ans=new double *[n];
                    for(int i=0;i<n;i++)
                        ans[i]=new double[n];
                    ans =transpose(vec,n);
                    for(int i=0;i<n;i++)
                    {
                        cout<<"\t\t";
                        for(int j=0;j<n;j++)
                            cout<<ans[i][j]<<' ';
                        cout<<endl;
                    }
                    for(int i=0;i<n;i++)
                        delete [] vec[i];
                    delete [] vec;
                    for(int i=0;i<n;i++)
                        delete [] ans[i];
                    delete [] ans;
                }
                else
                {
                    cout<<"\t\tDim error!!"<<endl;
                }
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO TRANSPOSE MENU: ";
                getline(cin,dummy);
                mm=10;
            }
        }
        //FOR DIV
        else if (mm==12)
        {
            system("CLS");
            int first;
            double num;
            cout<<"\n\n\t\tDIV MENU"<<endl;
            cout<<"\t\t1.Mat A 2.Mat B 3.Mat C 4.Mat ANS 5.Matrix menu\n\t\tChoose any option: ";
            cin>>first;
            clean();
            cout<<"Divided by:(input real number) ";
            cin>>num;
            clean();
            if(first==1)
            {
                ANS.copyMat(A/num);
                flagAns=1;
                cout<<"\t\tDIV RESULT:"<<endl;
                cout<<ANS<<endl;
            }
            else if(first==2)
            {
                ANS.copyMat(B/num);
                flagAns=1;
                cout<<"\t\tDIV RESULT:"<<endl;
                cout<<ANS<<endl;
            }
            else if(first==3)
            {
                ANS.copyMat(C/num);
                flagAns=1;
                cout<<"\t\tDIV RESULT:"<<endl;
                cout<<ANS<<endl;
            }
            else if(first==4 && flagAns==1)
            {
                ANS.copyMat(ANS/num);
                cout<<"\t\tDIV RESULT:"<<endl;
                cout<<ANS<<endl;
            }
            else if(first==5)
            {
                mm=-1;
            }
            else
            {
                cout<<"\t\tMatrix is not given or wrong input.Please Check!!" <<endl;
            }
            if(mm!=-1)
            {
                string dummy;
                cout<<"\t\tENTER ANY CHARACTER KEY TO GO TO DIV MENU: ";
                getline(cin,dummy);
                mm=12;
            }
        }
        else
        {
            mm=-1;
        }
    }
}
