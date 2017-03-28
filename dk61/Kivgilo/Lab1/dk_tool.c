#include <stdio.h>
#include "dk_tool.h"
	
float dobutok (int A,int B,int C)

{
	printf ("A = %i", A);
	printf ("\nB = %i",B);
	printf ("\nC = %i", C);
	float ab = A*B;
	printf ("ab= %.2f\n", ab);
	float bc = B+(C*C);
	
	printf ("b+c*c= %.2f", bc);
	if (bc==0)
		{
			printf ("Proveryai(B+C*C=0!!!)");
			return 0;
		}
	float D1= ab/bc;
	return D1;
}

float scan(int min, int max) 
{ 

float dobutok; 
int q; 
do 
{ 
q = scanf("%f", &dobutok); 

fflush(stdin); 

if((dobutok<min || dobutok>max) || q!=1) 
{ 
printf("\ngive me the correct number pls!"); 
} 

} 

while ((dobutok<min || dobutok>max) || q!=1); 

return dobutok; 

}

int  sum (int B)
{

	int U = 1, factorial = 1;
	if (B>0)
	{
		// summa 
		for (U ;U<=B;U++)
		{
			factorial = factorial*U;
		}
	}
	return factorial;
}
