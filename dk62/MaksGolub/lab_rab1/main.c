#include <stdio.h>
#include"dk_tool.h"

int main(void)
{
 double A=0, B=0, C=0;
 double drob=0, Q=0;
 printf("Enter the constant A:");
 scanf("%lf", &A);             //зчитування констант
 printf("Enter the constant B:");
 scanf("%lf", &B);
 printf("Enter the constant C:");
 scanf("%lf", &C);
 drob=(A+B+C)/(100-B-C); //дробова дія
 if(100-B-C!=0) //перевірка на нуль в знаменнику
 {
 double X = func_pow(A);
 Q=X+drob;
 printf("Result:%f\n", Q); //вивід
}
else
{
	printf("Error\n");
}
}
 
