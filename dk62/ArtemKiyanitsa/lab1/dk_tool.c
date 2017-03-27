#include <stdio.h>
//#include "dk_tool.h"
	
float dob (int A,int B,int C)
{
	printf ("A = %i", A);
	printf ("\nB = %i",B);
	printf ("\nC = %i\n", C);
	float ab = A*B;
	printf ("ab= %.2f\n", ab);
	float bc = B+(C*C);
	printf ("bc= %.2f", bc);
	if (bc==0)
		{
			printf ("Error(B+C*C=0!!!)");
			return 0;
		}
	float Q1;
	Q1 = ab/bc;
	return Q1;
}

int  sum (int B)
{
	float Q2;
	int D, i,factorial;
	Q2= 0;
	if (B>0)
	{
		// summa factorialov
		for (D=0;D<=B;D++)
		{
			//factorial
			factorial =1;
			for (i=1;i<=D; i++)
			{
				factorial = factorial*i;
			} 
			
		Q2= Q2 + factorial;
		}
	}
	else 
	printf ("B<0!!!!");
	return Q2;
}
