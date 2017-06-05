#include "Tool.h"
#include <stdlib.h>
#include <string.h>
 
int EnterWay(void)
{	
	char Str[10];
	int WayOfSorting = 0, character, Current = 0;
	do
	{		
		Current = 0;
		while ((character = getchar()) != '\n')
		{	
			if(Current<1)
			{		
				Str[Current] = (char)character;
				Current++;
			}
		}  
		WayOfSorting = atoi(Str);
		if(1 > WayOfSorting || WayOfSorting > 3)
			printf("Incorrect value!\n");
	}while(1 > WayOfSorting || WayOfSorting > 3);
}

float EnterElementToDelete(void)
{
	float Result;
	char ToFloat[3];
	int character, Current = 0;
	while ((character = getchar()) != '\n')
	{	
		if(Current<3)
		{				
			ToFloat[Current] =  (char)character;
			Current++;
		}
	}  
	printf("result = %1.1f", atof(ToFloat));
	return Result = atof(ToFloat);
}