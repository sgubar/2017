#include "tool.h"
#include "Element.h"
#include "List.h"
#include <stdlib.h>
#include <string.h>
 
int EnterIndex(DoubleList *aList)
{	
	char Str[2];
	int WayOfSorting = 0, character, Current = 0;
	do
	{		
		Current = 0;
		while ((character = getchar()) != '\n')
		{	
			if(Current<2)
			{		
				Str[Current] = (char)character;
				Current++;
			}
		}  
		if(Current == 1)
			Str[Current] = '\0';
		WayOfSorting = atoi(Str);
		if(0 > WayOfSorting || WayOfSorting > aList->count)
			printf("Incorrect value!\n");
	}while(0 > WayOfSorting || WayOfSorting > aList->count);
	return WayOfSorting;
}

int EnterValueOfElementToAdd(void)
{
	int result;
	char *ValueOfElementToAdd = (char *)malloc(11*sizeof(char));
	int character, Current = 0;
	while ((character = getchar()) != '\n')
	{	
		if(Current<10)
		{				
			ValueOfElementToAdd[Current] =  (char)character;
			Current++;
		}
	}  
	ValueOfElementToAdd[Current] = '\0';
	result = atoi(ValueOfElementToAdd);
	printf("String: %s\n", ValueOfElementToAdd);
	return result;
}
