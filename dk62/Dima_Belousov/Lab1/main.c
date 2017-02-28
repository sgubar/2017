#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char *argv[])
{
int a,b,c;
float result;

printf("Enter A:");
scanf("%i", &a);
printf("Enter B:");
scanf("%i", &b);
printf("Enter C:");
scanf("%i", &c);

result = ((float)(modul(a,b,c))/(float)(degree(c)))*(float)(sum(a));

printf("Result:");
printf("%f", result);

return 0;
}
