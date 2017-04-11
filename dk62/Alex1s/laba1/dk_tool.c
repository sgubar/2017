#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

unsigned long int factorial(int d)
{
if(!d)
	return 1;

int i;
unsigned long int result = 1;

for(i = 1; i <= d; i++)
    result *= i;
return result;
}

//-----------------------------------------------------------------------------------------------------------

double drob(int a, int b, int c)
{
if(b + my_square(c) == 0)
	{
	printf("Error!!!\n");
	exit(11);
	}
int xx = b + my_square(c);
double qq = a * b;
qq = qq / xx;
return qq;
}

//-----------------------------------------------------------------------------------------------------------

void enter_values(int *a, int *b, int *c)
{
printf("Enter A: ");
scanf("%i", *(&a));

printf("Enter B: ");
scanf("%i", *(&b));

printf("Enter C: ");
scanf("%i", *(&c));
}

//-----------------------------------------------------------------------------------------------------------

int my_square(int a)
{
return a*a;
}

//-----------------------------------------------------------------------------------------------------------

void sigma(double *Q, int B, int D)
{
for(D = 0; D <= B; D++)
	*Q += factorial(D);
}

//-----------------------------------------------------------------------------------------------------------

