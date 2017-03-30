#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BinarySearch(Garaj *PGar, char *aName)
{
	int Left = 0;
	int Right = PGar->curent - 1;
	int middle = 0;
	int Result = -1;
	
	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if(0==strcmp(PGar->kolvo[middle].Name, aName))
		{
			Result = middle;
			break;
		}
		else
		{
			if(1==strcmp(PGar->kolvo[middle].Name , aName))
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1;
			}
		}
	}
	return Result;	
}

void swap(Garaj *PGar, int aLeftIndex, int aRightIndex)
{
	Car theCarTmp = PGar->kolvo[aLeftIndex];
	PGar->kolvo[aLeftIndex] = PGar->kolvo[aRightIndex];
	PGar->kolvo[aRightIndex] = theCarTmp;
}
char *mediana(Garaj *PGar, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;
	
	if (1 == strcmp(PGar->kolvo[aLeftIndex].Name , PGar->kolvo[theCenter].Name))
	{
		swap(PGar, aLeftIndex, theCenter);
	}

	if (1 == strcmp(PGar->kolvo[aLeftIndex].Name , PGar->kolvo[aRightIndex].Name))
	{
		swap(PGar, aLeftIndex, aRightIndex);
	}

	if (1 == strcmp(PGar->kolvo[theCenter].Name , PGar->kolvo[aRightIndex].Name))
	{
		swap(PGar, theCenter, aRightIndex);
	}
	
	swap(PGar, theCenter, aRightIndex - 1);
	
	int lenth = strlen(PGar->kolvo[aRightIndex - 1].Name)+1;
	char *aPivot = (char *)malloc(sizeof(char)*lenth);
	strcpy(aPivot, PGar->kolvo[aRightIndex - 1].Name);
	
	return aPivot;
}

int m_partitionIt(Garaj *PGar, int aLeftIndex, int aRightIndex, char *aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex-1;
	
	while (1)
	{
		// search the bigest element
		while (-1 == strcmp(PGar->kolvo[++theLeft].Name , aPivot));
	
		// search the lowest element
		while (1 == strcmp(PGar->kolvo[--theRight].Name, aPivot));
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(PGar, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(PGar, theLeft, aRightIndex-1);
		
	free(aPivot);
	return theLeft; // return break position
}

void quickSort2(Garaj *PGar, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 3)
	{
		m_manualSort(PGar, aLeftIndex, aRightIndex);
	}
	else
	{
		char *thePivot = mediana(PGar, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(PGar, aLeftIndex, aRightIndex, thePivot);
		
		//left part sorting
		quickSort2(PGar, aLeftIndex, thePartitionIndex - 1);
		
		//right part sorting
		quickSort2(PGar, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(Garaj *PGar, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	
	if (theSize <= 1)
	{
		return;
	}
	
	if (2 == theSize)
	{
		if (1 == strcmp(PGar->kolvo[aLeftIndex].Name , PGar->kolvo[aRightIndex].Name))
		{
			swap(PGar, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes
		if (1 == strcmp(PGar->kolvo[aLeftIndex].Name , PGar->kolvo[aRightIndex - 1].Name))
		{
			swap(PGar, aLeftIndex, aRightIndex - 1);
		}
	
		if (1 == strcmp(PGar->kolvo[aLeftIndex].Name , PGar->kolvo[aRightIndex].Name))
		{
			swap(PGar, aLeftIndex, aRightIndex);
		}

		if (1 == strcmp(PGar->kolvo[aRightIndex - 1].Name , PGar->kolvo[aRightIndex].Name))
		{
			swap(PGar, aRightIndex - 1, aRightIndex);
		}
	}
}

Garaj *CreateGaraj(int Size){
	Garaj *PGar = (Garaj *)malloc(sizeof(Garaj));//sozdaem mashinu
	if(NULL != PGar)
	{
		PGar->max = Size;
		PGar->curent = 0;
		PGar->kolvo = (Car *)malloc(Size * sizeof(Car));//zabivaem mesto dlya koles
	}
	return PGar;	
}

void AddCar (Garaj *PGar,char *InpName){
	if (NULL != PGar)
	{
		if(PGar->curent<PGar->max)//proveryaem nalichie mesta dlya kolesa
		{
			Car *theCar = &(PGar->kolvo[PGar->curent]);//sozdaem ukazatel na koleso kotoroe dobavlyaem
			theCar->Name = (char *)malloc(sizeof(char)*(strlen(InpName)+1));//rezerviruem mesto pod pokrishku
			strcpy(theCar->Name, InpName);
			theCar->kolvo = (Koleso *)malloc(4 * sizeof(Koleso));
			theCar->max = 4;
			theCar->curent = 0;
			PGar->curent++;
		}
	}
}

void Vivod (Garaj *PGar){
	int i =0;
	while(i<PGar->curent)
	{
		printf("%s\n",PGar->kolvo[i].Name);
		i++;
	}
}

void DelCar(Car *PCar)
{
	if (NULL != PCar)
		{
			if(NULL != PCar->kolvo)
				free(PCar->kolvo);//udalyaem kolesa
			if (NULL != PCar->Name);
				free(PCar->Name);
		}
}

void DelGar(Garaj *PGar){
	if (NULL != PGar){
		if(NULL != PGar->kolvo){
			int i;
			for(i=0;i<PGar->curent;i++){
				
				Car *PCar = &PGar->kolvo[i];
				if (NULL != PCar)
				{					
					DelCar(PCar);
				}	
			}			
			free(PGar->kolvo);		
		}
		free(PGar);		
	}
}
