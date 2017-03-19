#include <stdio.h>
#include <stdlib.h>
#include "labdk_tool.h"

void program(int A, int B, int C)
{
    int A1=0;   //modul A  
    int B1=0;   //modul B
    int C1=0;   //modul C
    float d=0;  //B+5^C
    int u=0;    //A^2+B^2
    float st=1; //stepen
    int r=1;    //B!
    /////////////////////moluli A,B,C
    if(A<0)
    {
        A1=abs(A);
    }
    else
    {
        A1=A;
    }
    //.............
    if(B<0)
    {
        B1=abs(B);
    }
    else
    {
        B1=B;
    }
    //..............
    if(C<0)
    {
        C1=abs(C);
    }
    else
    {
        C1=C;
    }
    ///////////uznaem U
    u=A1*A1+B1*B1;
    ////////////////////////////////////raschet B+5^C
    //schitaem stepen
    if(C>0)
    {
        for(int i=1;i<=C;i++)
        {
            st*=5;
        }
    }
    else if(C==0)
    {
        st=1;
    }
    else if(C<0)
    {
        for(int j=1;j<=C1;j++)
        {
            st/=5;
        }
    }
    //////////////
    d=B+st;
    //............................proverka d
    if(d==0)        
    {             
        printf("Невозможно посчитать!!!\n");
        exit(0);
         
    }      
    //...........................
    //////////////////////////////////////////raschet B!
    for(int k=1;k<=B1;k++)
    {
        r*=k;
    }
    /////////////////////////summa
    float Q=u/d+r;  //...(A^2+B^2)/(B+5^C)+B!
    printf("Q = %f\n",Q);
}
