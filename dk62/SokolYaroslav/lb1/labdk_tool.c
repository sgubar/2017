#include <stdio.h>
#include <stdlib.h>
#include "labdk_tool.h"
void program(int A, int B, int C)
{
    float d=0;  
    float st=1; 
    int fact=1;   
	 
    int u=A*A+B*B;
	stepen(C,st);
    d=B+st;

    if(d==0)        
    {             
        printf("?????????? ?????????!!!\n");
        exit(0);
         
    }      
	int factorial(int B,int fact);

    float Q=(A*A+B*B)/(B+st)+fact;
    printf("Q = %f\n",Q);
}

int proverka(int chislo, int gran)
{
	if(scanf("%i",&chislo)!=1)
    {
        printf("Vi vveli bukvu!!!\n");
        exit(0);
    }
    if(chislo>gran||chislo<-gran)
    {
        printf("Vvedite chislo ot -1000 do 1000!!!\n");
        exit(0);
    }
    return chislo;
}

int stepen(int C,int chislo)
{
	    if(C>0)
    {
    	int i=1;
        for(i=1;i<=C;i++)
        {
            chislo*=5;
        }
    }
    else if(C<0)
    {
    	int j=1;
        for(j=1;j<=C;j++)
        {
            chislo/=5;
        }
    }
    return chislo;
}

int factorial(int B,int chislo)
{
	int k=0;
    for(k=0;k<=B-1;k++)
    {
        chislo*=k;
    }
    return chislo;
}
