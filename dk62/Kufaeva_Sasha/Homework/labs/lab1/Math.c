#include <stdio.h>
#include "Math.h"


int Divide (int A, int B, int C)
{
    int TheResult = 0;
    int Zn = B+POW(5,C);
    
    if( Zn == 0){
        printf( "Oshibka");
        return -1;
    }
    
    TheResult=((A*A)+(B*B))/Zn;
    return TheResult;
    
}

 int POW (int Number, int Stepen)
{
    for(int j = 0; j < Stepen; j++)
     Number = Number* Number;
       


     return Number;

}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return factorial(n-1)*n;
}
