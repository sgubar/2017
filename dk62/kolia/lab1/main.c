#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[])
{
	int A;
	int C;
	int B;
	printf ("a = \n");
	scanf ("%i", &a);
	printf ("b = \n");
	scanf ("%i", &b);
	printf ("c = \n");
	scanf ("%i", &c);
	float Q;
	float Q1 = dob( a, b, c);
	printf ("\n");
	printf ("Q1= %.3f \n",Q1);
	int Q2 = sum(b);
	printf ("Q2= %i\n", Q2);
	Q= Q1+Q2;
	printf ("Q= %.3f\n", Q);
	return 0;
}
