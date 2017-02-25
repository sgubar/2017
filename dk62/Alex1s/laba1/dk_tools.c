#include <stdio.h>

unsigned long int factorial(int d) //the second part of the formula
{
if(d == 0)
	{
	int h = 1;
	return h;
	}

int i = 0;
unsigned long int result = 1;      //can be a very large number

for(i = 1; i <= d; i++)
    {
    result *= i;                   //result = result * i;
    }
return result;
}

double drob(int a, int b, int c)   //the first part of the formula
{
if(b+c*c == 0)                     //division by zero
	{
	printf("Error!\n");
	return 1;
	}
int xx = b + (c*c);
double qq = a*b;
qq = qq/xx;
return qq;
}
