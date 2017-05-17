#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

#define M_PI 3.14159265358979323846

list *createList(int aSize)
{
    list *aList = (list *)malloc(sizeof(list));
    if(aList != NULL)
	{
		aList->circle = (coordinates *)calloc(aSize, sizeof(coordinates));
		aList->maxSize = aSize;
		aList->currentSize = 0;
	}
	return aList;
}


void destroyList(list *List)
{
	if(NULL != List)
	{
		if(NULL != List->circle)
		{
			free(List->circle);
		}
		free(List);
	}
}


void newCoordinate(list *aList)
{
	if(NULL != aList)
	{
		if(aList->currentSize < aList->maxSize)
		{
			coordinates *aCurrent = &(aList->circle[aList->currentSize]);
			printf("Enter x koordinate: ");
			scanf("%f", &aCurrent->x);
			
			printf("Enter y koordinate: ");
			scanf("%f", &aCurrent->y);
			do{
				printf("Enter radius : ");
				scanf("%f", &aCurrent->r);
			}while(aCurrent->r < 0);

			printf("\nResult: %.12f\n\n", square(aCurrent));
			aList->currentSize++;
		}
	}
}


float square(coordinates *current)
{
	float result = M_PI * current->r * current->r;
	
	if(result < 0) 
		result *= -1;

	return result;
}

void printArea(list *aList)
{
	if(NULL != aList)
	{
		int i;
		for(i = 0; i < aList->currentSize; i++)
		{
			coordinates *aCurrent = &(aList->circle[i]);
			printf("Circle[%i]: \"X\":%.3f", i, aCurrent->x);
			printf(" \"Y\":%.3f \"Radius\":%.3f", aCurrent->y, aCurrent->r);
			printf(" \"Square\":%.3f\n", square(aCurrent));
		}
	}
}
