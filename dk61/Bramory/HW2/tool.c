#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "tool.h"

float Square (Circle *aCircle)
{
	return 3.14159*aCircle->radius * aCircle->radius;
}

FigureList *createFigureList ( int aSize)
{
	FigureList *theList = (FigureList *)malloc (sizeof(FigureList));
	if (theList != NULL)
	{
		theList -> circles = (Circle *) malloc(aSize * sizeof(Circle));
		memset(theList -> circles, 0, aSize * sizeof(Circle) );	
			
		theList -> size = aSize;
		theList -> current_size = 0;
	}
	
return theList;
}


void destroyFigureList(FigureList *aList)
{
	if (NULL != aList)
	{
		if(NULL != aList -> circles)
		{		
			free(aList->circles);
		}
	free(aList);
	}
}


int addCircle (FigureList *aList, int x, int y, int radius)
{
	if (NULL != aList && 0 <= radius )
	{
		if ( aList->current_size < aList -> size )
		{
			Circle *theCircle = &(aList -> circles [aList -> current_size] );
				if (NULL != theCircle)
			{
				theCircle -> x = x;
				theCircle -> y = y;
				theCircle -> radius = radius;		
				
				aList -> current_size ++;
			}
		}
		else
		{
			return -2;
		}
	}
	else 
	{
		return -1;
	}
	return 0; 
}
