#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, const char *argv[])
{

int a = 0, b = 0;
double result = 0;

do{
printf("Enter value A: ");
scanf("%i",&a);
}while(a < 0);

do{
printf("Enter value B: ");
scanf("%i",&b);
}while(2*a + b == 0);

result = dilennya(a, b);

printf("Q = %.3lf\n", result);

system("pause");
return 0;
}

