#include <stdio.h>

float dob (int a,int b,int c)
{
	printf ("a = %i", a);
	printf ("\nb = %i",b);
	printf ("\nc = %i\n", c);
	float AB = a*b;
	printf ("AB= %.3f\n", AB);
	float BC = b+(c*c);
	printf ("BC= %.3f", BC);
	if (BC==0)
		{
			printf ("Error(b+c*c=0!)");
			return 0;
		}
	float Q1;
	Q1 = AB/BC;
	return Q1;
}

int  sum (int B)
{
	float Q2;
	int D, i,factorial;
	Q2= 0;
	if (B>0)
	{

		for (D=0;D<=B;D++)
		{

			factorial =1;
			for (i=1;i<=D; i++)
			{
				factorial = factorial*i;
			}

		Q2= Q2 + factorial;
		}
	}
	else
	printf ("B<0!");
	return Q2;
}
