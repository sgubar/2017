#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) 
{
	int A;
	int C;
	int B;
	printf ("A = ");
	scanf ("%i", &A);
	printf ("B = ");
	scanf ("%i", &B);
	printf ("C = ");
	scanf ("%i", &C);
	float Q;
	float Q1 = dob( A, B, C);
	printf ("\n");
	printf ("Q1= %.2f \n",Q1);
	int Q2 = sum(B);
	printf ("Q2= %i\n", Q2);
	Q= Q1+Q2;
	printf ("Q= %.2f\n", Q);
	return 0;
}
