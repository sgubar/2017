#include <stdio.h>
#include <string.h>
#include <math.h>
#include"dk_tool.h"

double peremennaya(int A, int B,int C)
{
	if(C != 0) 
		{
			double drib, dobutok, summa=0;
			drib=(abs((A*C)-B))/(pow(C,3));
			int D=0;
			for(D=0; D<=A; D++)
				{
					summa = summa + pow(2,D);
				}
			dobutok=drib*summa;
			printf("Vidpovid=%f", dobutok);
			return dobutok;
		}
	else
		{
				printf("C ne moze dorivnuvatu 0\n");
				return 0;
		}
}
