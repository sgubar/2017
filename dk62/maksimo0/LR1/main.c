#include <stdio.h>
#include "dk_tool.h"

void main(int argc, const char * argv[])
{
    int A=0, B=0, C=0;
    printf("Vvedit chisla A, B(ne dorivnue nulu), C:\n");
    scanf("%i%i%i", &A, &B, &C);                              //зчитування даних
    double Q=Obchislennya_Za_Formulou(A,B,C);                 //виклик функціїї для обчислення результату за формулою
    printf("Rezultat:%.3Lf",Q);                               //вивід результату обчислення на екран
}
