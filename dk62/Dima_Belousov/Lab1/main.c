#include <stdio.h>
#include <stdlib.h>
#include "dk_tools.h"

int main(int argc, char *argv[])
{
int a,b,c;
float mod,deg,su,res;

printf("Enter A:");
scanf("%i", &a);
printf("Enter B:");
scanf("%i", &b);

do{
printf("Enter C != 0 :");
scanf("%i", &c);}while(c==0);

mod = (float)modul(a,b,c);
deg = (float)degree(c);
su = (float)sum(a);

printf("Modul: %f\n", mod);
printf("Degree: %f\n", deg);
printf("Sum: %f\n", su);

res = result(mod,deg,su);

printf("Result: %f\n", res);


return 0;
}

