//
//  Lab_ONE_K.c
//  KPI
//
//  Created by air on 23.02.17.
//
//

#include "dk_tool.h"

int D=0;//zero pointer

float MathDEL(int A, int B, int C)
{
    float DEL;
    float SecondDel = (100-B-C);
    if(SecondDel == 0)
    {
        printf("Error. != 0\n");
        return -1;
    }else
        DEL = (A+B+C)/SecondDel;
    
    return DEL;
}

int MathST(int A)
{
    
    int ST=1;
    for(int i=0;i<D+A;i++){
        ST = 2*ST;
    }
    
    return ST;
}

int MathSUMM(int A, int B, int C)
{
    int summ=0;
    for(int i=D;i<=A;i++)
    {
        summ = summ+i;
    }
    return summ;
}
