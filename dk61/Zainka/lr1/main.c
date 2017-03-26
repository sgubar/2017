#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include "dk_tool.h" 

int main()
{
int B;
int D;
int G;
int A;
int K;
int Otvet;
int C;
 int R;

printf("Vvedit tchislo A\n");
scanf("%i" , & A);
{
G = pow2(A); 
printf(" %i stepen" , G);
}

printf("Vvedit tchislo B\n");
scanf("%i" , & B);
{

D = pow2(B) ;	
printf(" %i" , D);
}
{

K = fact(B);
printf(" %i" , K);
}
printf("vvod tchislo C\n");
scanf("%i" , & C);
R = pow2(C);
printf(" %i" , R);

Otvet = (G + D)/(B + R) + K;
printf(" %i = otvet" , Otvet);



}



