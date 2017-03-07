//
//  dk_tool.c
//  Lab_one
//
//  Created by air on 01.03.17.
//  Copyright © 2017 Oleg Kuzhilnyi. All rights reserved.
//

#include "dk_tool.h"

float MathDEL(int A, int B, int C)
{
    float divide;
    float divideOnNULL = (100-B-C);//variable for check divide on 0
    if(divideOnNULL == 0)//check (if znamenatel' != 0, - OK)
    {
        printf("Error. != 0\n");
        exit(1); //exit from programm
    }else
        divide = (A+B+C)/divideOnNULL;
    
    return divide;
}

double MathDegree(int A, int B, int C)
{
    int D=0;//zero pointer
    double Degree=1;// counter for exponent. For example: [0]: 2^1 || 2^degree but not 2^0
    double SigmaSUMdegree=0;
   //int counter = 0;
    
    if( A < 0) // check if stepen' is negative
     {
         for(int i=0;i<A*(-1);i++)
         {
             Degree *= 0.5;// if 2^negativ stepen'  => 1/2
         }
         for(int i=D;i<A*(-1);i++)
         {
             SigmaSUMdegree += Degree; //count for summ All elements
         }
         
     }else
     {
         for(int j=D;j<D+A;j++)
         {
             Degree *= 2;//count for exponent 2^(A+D)
         }
         
         for(int j=D;j<D+A;j++)
         {
             SigmaSUMdegree += Degree; //count for summ All elements
         }
         
     }if  (A==0)
     {
         Degree = 1;  // 2^0 = 1
         SigmaSUMdegree = 1; // summ = 1
     }

    
    return SigmaSUMdegree;
}
