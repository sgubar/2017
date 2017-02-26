//
//  main.c
//  KPI
//
//  Created by air on 23.02.17.
//
//  Varian 4

#include "dk_tool.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    int Number_A=0;
    int Number_B=0;
    int Number_C=0;
    
    printf("A: ");
    scanf("%i", &Number_A);
    printf("B: ");
    scanf("%i", &Number_B);
    printf("C: ");
    scanf("%i", &Number_C);
    
    int theResultSUMM = MathSUMM(Number_A, Number_B, Number_C);
    int theResultST = MathST(Number_A);
    float theResultDEL = MathDEL(Number_A, Number_B, Number_C);
   
    
    float Q = (theResultSUMM * theResultST) + theResultDEL;
    
    printf("The Result Q: <%.2f> \n", Q);
    
    printf("ST: %i\n", theResultST); //cheking ST
    printf("DEL: %.2f\n",  theResultDEL);//cheking DEL
    printf("SUMM: %i\n", theResultSUMM);//cheking SUMM
    return 0;
}
