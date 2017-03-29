#include <stdio.h>
#include "dk_tool.h"

unsigned long int factorial(int d) {
if(d == 0)
	return 1;

int i = 0;
unsigned long int result = 1;

for(i = 1; i <= d; i++)
    result *= i;
return result;
}


//--------------------------------------------------------------------------------------------------------------------------------


double drob(int a, int b, int c)
{
if(b+c*c == 0)
	{
	printf("Error!\n");
	return 1;
	}
int xx = b + (c*c);
double qq = a*b;
qq = qq/xx;
return qq;
}


//--------------------------------------------------------------------------------------------------------------------------------


int enter_value(int a)
{
printf("Enter value: ");
scanf("%d", &a);
return a;
}


