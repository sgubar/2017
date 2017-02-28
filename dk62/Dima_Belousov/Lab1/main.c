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

do{
printf("Enter C != 0 :");
scanf("%i", &c);}while(c==0);

result = ((float)(modul(a,b,c))/(float)(degree(c)))*(float)(sum(a));

printf("Result:");
printf("%f", result);

return 0;
}
