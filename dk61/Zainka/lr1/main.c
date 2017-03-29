#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "dk_tool.h" 

int main()
{
float B;
float D;
float G;
float A;
float K;
float Otvet;
float C;
 float R;

printf("Vvedit tchislo A\n");
scanf("%f" , & A);
{
G = pow2(A); 
printf(" %f stepen\n" , G);
}

printf("Vvedit tchislo B\n");
scanf("%f" , & B);
{

D = pow2(B) ;	
printf(" %f\n" , D);
}
{

K = fact(B);
printf(" %ffact\n" , K);
}
printf("vvod tchislo C\n");
scanf("%f" , & C);
R = pow2(C);
printf(" %f\n" , R);

Otvet = (G + D)/(B + R) + K;
printf(" %f = otvet" , Otvet);
}



