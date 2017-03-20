#include "dk_tool.h"
#include <stdio.h>



long int factorial(int d)
{
if(d == 0)
	return 1;

int r;
long int result = 1;

for(r = d; r != 0; r--)
    result *= r;
return result;
} 



double dilennya(int a, int b)
{
double Q = factorial(a);
int GG = 2 * a + b;
Q = Q/abs(GG);
return Q;
}
