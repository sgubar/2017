#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

Triangles *createList()
{
	Triangles *Element = (Triangles *) malloc(sizeof(Triangles));
	if(!Element)
		exit(10);
	
	Element->maxSize = 5;
	Element->currentSize = 0;
	
	int i;
	for(i = 0; i < 5; i++)
	{
		Element->place[i] = (Figure *) malloc(sizeof(Figure));
		if(!Element->place)
		{
			free(Element);
			exit(11);
		}
	}
	return Element;
}

//-----------------------------------------------------------------------------------------------------------

int createTriangle(Triangles *Element)
{
	if(Element->currentSize < Element->maxSize)
	{
		Figure *aCurrent = Element->place[Element->currentSize];
		
		if(aCurrent)
		{
			aCurrent->A = (Dot *) malloc(sizeof(Dot));
			aCurrent->B = (Dot *) malloc(sizeof(Dot));
			aCurrent->C = (Dot *) malloc(sizeof(Dot));
			
			if(aCurrent->A && aCurrent->B && aCurrent->C)
			{
				enterCoor(aCurrent);
				printf("\nCreate done!\n");
				
				double j = calcArea(aCurrent);
				printf("Area: %lf\n\n", j);
				
				Element->currentSize++;
				aCurrent = NULL;
				return 0;
			}
			
			aCurrent = NULL;
			return 3;
		}
		
		aCurrent = NULL;
		return 2;
	}
	else
		return 1;
}

//-----------------------------------------------------------------------------------------------------------

void enterCoor(Figure *aCurrent)
{
	printf("Enter x[0] coordinate: ");
	scanf("%f", &(aCurrent->A->X));
	
	printf("Enter y[0] coordinate: ");
	scanf("%f", &(aCurrent->A->Y));
	
	printf("Enter x[1] coordinate: ");
	scanf("%f", &(aCurrent->B->X));
	
	printf("Enter y[1] coordinate: ");
	scanf("%f", &(aCurrent->B->Y));
	
	printf("Enter x[2] coordinate: ");
	scanf("%f", &(aCurrent->C->X));
	
	printf("Enter y[2] coordinate: ");
	scanf("%f", &(aCurrent->C->Y));
}

//-----------------------------------------------------------------------------------------------------------

double calcArea(Figure *aCurrent)
{
	double result, tmp;
	result = (aCurrent->A->X - aCurrent->C->X);
	result *= (aCurrent->B->Y - aCurrent->C->Y);
	tmp = (aCurrent->B->X - aCurrent->C->X);
	tmp *= (aCurrent->A->Y - aCurrent->C->Y);
	result -= tmp;
	result /= 2;
	
	if(result < 0)
		result *= -1;
	return result;
}

//-----------------------------------------------------------------------------------------------------------

void deleteList(Triangles *Element)
{
	if(Element)
	{
		int i;
		for(i = 0; i < Element->maxSize; i++)
		{
			deleteTriangle(Element, i);
			free(Element->place[i]);
		}
		
		free(Element);
	}
}

//-----------------------------------------------------------------------------------------------------------

void deleteTriangle(Triangles *Element, int i)
{
	if(i < Element->currentSize)
	{
		Figure *aCurrent = Element->place[i];
		
		free(aCurrent->A);
		free(aCurrent->B);
		free(aCurrent->C);
		
		Element->currentSize--;
	}
}

//-----------------------------------------------------------------------------------------------------------

void printTriangles(Triangles *Element)
{
	if(Element)
	{
		int i;
		for(i = 0; i < Element->currentSize; i++)
			printTriangle(Element, i);
	}
}

//-----------------------------------------------------------------------------------------------------------

void printTriangle(Triangles *Element, int i)
{
	if(Element)
	{
		Figure *aCurrent = Element->place[i];
		printf("\nFigure #%i\nArea: %f\n", i, calcArea(aCurrent));
		printf("Dot [0]: X:%.3f\tY:%.3f\n", aCurrent->A->X, aCurrent->A->Y);
		printf("Dot [1]: X:%.3f\tY:%.3f\n", aCurrent->B->X, aCurrent->B->Y);
		printf("Dot [2]: X:%.3f\tY:%.3f\n", aCurrent->C->X, aCurrent->C->Y);
	}
}

//-----------------------------------------------------------------------------------------------------------

void shellSort(Triangles *Element)
{
	int i = 0, j = 0, H = 1;
	
	while(H <= Element->currentSize / 3)
		H = H * 3 + 1;
	
	while(H > 0)
	{
		for(j = H; j < Element->currentSize; j++)
		{
			Figure *aTmp = Element->place[j];
			i = j;
			
			while(i > H - 1 && calcArea(Element->place[i - H]) >= calcArea(aTmp))
			{
				(Element->place[i]) = (Element->place[i - H]);
				i -= H;
			}
			(Element->place[i]) = (aTmp);
			aTmp = NULL;
		}
		H = (H - 1) / 3;
	}
}

//-----------------------------------------------------------------------------------------------------------

int lineSearch(Triangles *Element, double val)
{
	int i;
	for(i = 0; i < Element->currentSize; i++)
	{
		if(calcArea(Element->place[i]) == val)
			return i;
	}
	return -1;
}

//-----------------------------------------------------------------------------------------------------------

