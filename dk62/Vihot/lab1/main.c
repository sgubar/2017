#include <stdio.h>
#include "dk_toollab1.h"

void main(int argc, const char * argv[])
{
    int A=0, B=0, C=0;
    printf("Vvedit chisla A, B, C:\n");
    scanf("%i%i%i", &A, &B, &C);                              
    formula(A,B,C);                          
}
