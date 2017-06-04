#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

#define M_PI 3.14159265358979323846

list *createList(int aSize)
{
    list *aList = (list *) malloc(sizeof(list));
    if(aList != NULL)
	{
		aList->circle = (coordinates *) calloc(aSize, sizeof(coordinates));
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

float square(coordinates *aCurrent)
{
	return M_PI * aCurrent->r * aCurrent->r;
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
		printf("\n");
	}
}

void shellSort(list *aList)
{
	int i = 0, j = 0, H = 1; 
	
	while(H <= aList->currentSize / 3)
		H = H * 3 + 1;
	
	while(H > 0)
	{
		for(j = H; j < aList->currentSize; j ++)
		{
			coordinates Tmp = aList->circle[j];
			i = j;
			while(i > H-1 && square(&aList->circle[i - H]) >= square(&Tmp))
			{
				aList->circle[i] = aList->circle[i - H];
				i -= H;
			}
			aList->circle[i] = Tmp;
		}
		H = (H - 1) / 3;
	}
}

int lineSearch(list *aList)
{
	int i;
	float val;
	coordinates *tmp;
	
	do{
		printf("Enter radius to search: ");
		scanf("%f", &val);
	}while(val <= 0);
	
	for(i = 0; i < aList->currentSize; i++)
	{
		tmp = &aList->circle[i];
		if(tmp->r == val)
			return 0;
	}
	return 1;
}
