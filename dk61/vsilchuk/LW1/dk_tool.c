#include "dk_tool.h"
#include <stdio.h>

int NumInput()
{
	int Num;
	int Proof;								
					
	while(1)
	{						
		Proof = scanf("%d", &Num);
		if(Proof == 1)		 		
			{
				break;
			}
		printf("Please enter another number:\n");
		fflush (stdin); 				
	}
	return Num;
}

int Sum(int A)
{
	int sumResult = 0;
	int D;
	
	for(D = 0; D <= A; D++)
		{
			sumResult += Pow(2, A+D);
		}
		
	return sumResult;
}

int Pow(int PowNum, int theExponent)
{
	int powResult = 1;
	int Counter;
	
	for(Counter = 0; Counter < theExponent; Counter++)
		{
			powResult *= PowNum;
		}
	
	return powResult;
}


