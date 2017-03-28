#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int A;
	int C;
	int B;
	printf ("A = ");
	scanf ("%i", &A);
	printf ("\nB = ");
	scanf ("%i", &B);
	printf ("\nC = ");
	scanf ("%i", &C);
	float D;
	float D1 = dobutok( A, B, C);
	printf ("\n");
	printf ("D1= %.2f \n",D1);
	int D2 = sum(B);
	printf ("D2= %i\n", D2);
	D= D1+D2;
	printf ("D= %.2f\n", D);
	return 0;
}
