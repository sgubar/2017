#include <stdio.h>
#include"dk_tool.h"

int main(void)
{
 double A=0, B=0, C=0;
 double drob=0, Q=0;
 \\опитування значень
 printf("Enter the constant A:");
 scanf("%lf", &A); 
 printf("Enter the constant B:");
 scanf("%lf", &B);
 printf("Enter the constant C:");
 scanf("%lf", &C);
 drob=(A+B+C)/(100-B-C);
 \\виклик функції
 double X = func_pow(A);
 Q=X+drob;
 printf("Result:%f\n", Q);
}
 
