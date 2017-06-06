#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
#include <math.h>

//float areaCalculation(ParpipedPoints *aParpiped);

ParpipedList * createParpipedList(int aSize)
{
	ParpipedList *theParpipedList = (ParpipedList *)malloc(sizeof(ParpipedList));

	if (theParpipedList != NULL)
	{
		theParpipedList->parpipeds = (ParpipedPoints *)malloc(aSize * sizeof(ParpipedPoints));
		memset(theParpipedList->parpipeds, 0, sizeof(ParpipedPoints));

		theParpipedList->size = aSize;
		theParpipedList->current_size = 0;
	}
	return theParpipedList;
}

void destroyParpipedList(ParpipedList *aParpiped)
{
	if (NULL != aParpiped)
	{
		if (NULL != aParpiped->parpipeds)
		{

			free(aParpiped->parpipeds);
		}
		free(aParpiped);
	}
}

int addParpipedCoordinates(ParpipedList *aParpiped)
{
	int i;
	if (NULL != aParpiped)
	{
		if (aParpiped->current_size < aParpiped->size)
		{
			ParpipedPoints *theParpiped = &(aParpiped->parpipeds[aParpiped->current_size]);
			if (NULL != theParpiped)
			{
				theParpiped->coordinates = (ParpipedCoordinate *)malloc(sizeof(ParpipedCoordinate) * 8);
				for (i = 0; i < 8; i++)
				{
					printf("Enter x , y , z for point[%d]\n", i + 1);
					theParpiped->coordinates[i].xCoordinate = enterParpipedCoordinate();
					theParpiped->coordinates[i].yCoordinate = enterParpipedCoordinate();
					theParpiped->coordinates[i].zCoordinate = enterParpipedCoordinate();
				}
				aParpiped->current_size++;
			}

		}
		else
			return -3;
	}
	else
	{
		return -2;
	}
	return 0;
}




void printParpipedList(ParpipedList *aParpiped)
{
	int i;
	for (i = 0; i < aParpiped->current_size; i++)
	{
		printf("Struct [%d]\n", i + 1);
		ParpipedPoints *theParpiped = &(aParpiped->parpipeds[i]);
		printParpiped(theParpiped);
		printf("\n");
		printf("%d parellelepiped has area: %d\n", i + 1, areaCalculation(theParpiped));
	}
}


int printParpiped(ParpipedPoints *theParpiped)
{
	int i;
	if (NULL != theParpiped)
	{
		for (i = 0; i < 8; i++)
		{
			printf("Point[%d]={%d, %d, %d}\n", i + 1, theParpiped->coordinates[i].xCoordinate, theParpiped->coordinates[i].yCoordinate, theParpiped->coordinates[i].zCoordinate);
		}
	}
	return 0;
}

int areaCalculation(ParpipedPoints *aParpiped)
{
	int x;
	int y;
	int z;
	float straightLen14;
	float straightLen34;
	float straightLen48;

	x = (aParpiped->coordinates[0].xCoordinate) - (aParpiped->coordinates[3].xCoordinate);
	y = (aParpiped->coordinates[0].yCoordinate) - (aParpiped->coordinates[3].yCoordinate);
	z = (aParpiped->coordinates[0].zCoordinate) - (aParpiped->coordinates[3].zCoordinate);
	straightLen14 = sqrt((x * x) + (y * y) + (z * z));
	x = 0;
	y = 0;
	z = 0;

	x = (aParpiped->coordinates[2].xCoordinate) - (aParpiped->coordinates[3].xCoordinate);
	y = (aParpiped->coordinates[2].yCoordinate) - (aParpiped->coordinates[3].yCoordinate);
	z = (aParpiped->coordinates[2].zCoordinate) - (aParpiped->coordinates[3].zCoordinate);
	straightLen34 = sqrt((x * x) + (y * y) + (z * z));
	x = 0;
	y = 0;
	z = 0;


	x = (aParpiped->coordinates[3].xCoordinate) - (aParpiped->coordinates[7].xCoordinate);
	y = (aParpiped->coordinates[3].yCoordinate) - (aParpiped->coordinates[7].yCoordinate);
	z = (aParpiped->coordinates[3].zCoordinate) - (aParpiped->coordinates[7].zCoordinate);
	straightLen48 = sqrt((x * x) + (y * y) + (z * z));
	x = 0;
	y = 0;
	z = 0;



	int fullArea = 2 * ((straightLen14 * straightLen34) + (straightLen14 * straightLen48) + (straightLen34 * straightLen48));

	return fullArea;



}


int enterParpipedCoordinate(void)
{
	int a;
	do
	{
		int theTmp = scanf("%d", &a);
		if (theTmp == 1)
		{
			break;
		}
		printf("Please,try again: ");
		fflush(stdin);
	} while (1);

	return a;
}


void writeParpiped(FILE *aFile, ParpipedPoints *theParpiped)
{
	int i;
	for (i = 0; i < 8; i++) {
		fprintf(aFile, " \"point[%d]\"={%d,%d,%d},\n", i + 1, theParpiped->coordinates[i].xCoordinate, theParpiped->coordinates[i].yCoordinate, theParpiped->coordinates[i].zCoordinate);
	}

}

void writeParpipedList(FILE *aFile, ParpipedList *aParpipedList)
{
	fprintf(aFile, "{\n");
	fprintf(aFile, "  \"size\":%d;\n", aParpipedList->size);
	fprintf(aFile, "  \"current size\":%d;\n\n", aParpipedList->current_size);
	fprintf(aFile, "  \"Parpipeds\":[\n");

	int i;
	for (i = 0; i < aParpipedList->current_size; i++)
	{
		ParpipedPoints *theParpiped = &(aParpipedList->parpipeds[i]);

		fprintf(aFile, "  \"Parpiped #%d\" :\n", i + 1);
		fprintf(aFile, "{\n");
		writeParpiped(aFile, theParpiped);
		if (i < aParpipedList->current_size - 1)
		{
			fprintf(aFile, "},\n\n");
		}
		else
			if (i <= aParpipedList->current_size - 1)
				fprintf(aFile, "}\n\n");

	}
	fprintf(aFile, "]\n");
	fprintf(aFile, "}\n");
}

int BinarySearch(ParpipedList *aList, int aValue)
{
	int theRightLimit = aList->current_size - 1;
	int theLeftLimit = 0;
	int theResult = aList->current_size;
	int middleValue = 0;

	while (1)
	{
		int middleValue = (theLeftLimit + theRightLimit) / 2;

		if (areaCalculation(&aList->parpipeds[middleValue]) == aValue)
		{
			theResult = middleValue;
			printf("Searched Parpiped is located on %d position\n", theResult+1);
			return theResult;
			break;
		}
		else if (theLeftLimit > theRightLimit)
		{
			break;
		}
		else
		{
			if (areaCalculation(&aList->parpipeds[middleValue]) > aValue)
			{
				theRightLimit = middleValue - 1;
			}
			else
			{
				theLeftLimit = middleValue + 1;
			}
		}
	}
	return -1;

}
