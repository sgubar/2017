#include "Tool.h"
#include <stdlib.h>
#include <string.h>
 

double EnterElementToDelete(void)
{
	double Result;
	char ToDouble[4];
	int character, Current = 0;
	while ((character = getchar()) != '\n')
	{	
		if(Current<4)
		{				
			ToDouble[Current] =  (double)character;
			Current++;
		}
	}  
	printf("result = %0.2f", atof(ToDouble));
	return Result = atof(ToDouble);
}
