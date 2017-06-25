#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Park *CreatePark(int Size)
{
	Park *PointerPark = (Park *)malloc(sizeof(Park));
	if(NULL != PointerPark)
	{
		PointerPark->max = Size;
		PointerPark->curent = 0;
		PointerPark->kolvo = (Car *)malloc(Size * sizeof(Car));
	}
	return PointerPark;	
}

void AddCar (Park *PointerPark,char *InpName)
{
	if (NULL != PointerPark)
	{
		if(PointerPark->curent<PointerPark->max)//checking space 4 koleso
		{
			Car *theCar = &(PointerPark->kolvo[PointerPark->curent]);//pointer on addKoleso
			theCar->Name = (char *)malloc(sizeof(char)*(strlen(InpName)+1));//space 4 name
			strcpy(theCar->Name, InpName);
			theCar->kolvo = (Koleso *)malloc(4 * sizeof(Koleso));
			theCar->max = 4;
			theCar->curent = 0;
			PointerPark->curent++;
		}
	}
}

void Print (Park *PointerPark)
{
	int i =0;
	while(i<PointerPark->curent)
	{
		printf("%s\n",PointerPark->kolvo[i].Name);
		i++;
	}
}

void DeleteCar(Car *PointerCar)
{
	if (NULL != PointerCar)
		{
			if(NULL != PointerCar->kolvo)
				free(PointerCar->kolvo);
			if (NULL != PointerCar->Name);
				free(PointerCar->Name);
		}
}

void DeletePark(Park *PointerPark)
{
	if (NULL != PointerPark)
	{
		if(NULL != PointerPark->kolvo){
			int i;
			for(i=0;i<PointerPark->curent;i++){
				
				Car *PointerCar = &PointerPark->kolvo[i];
				if (NULL != PointerCar)
				{					
					DeleteCar(PointerCar);
				}	
			}			
			free(PointerPark->kolvo);		
		}
		free(PointerPark);		
	}
}

void swap(Park *PointerPark, int aLeftIndex, int aRightIndex)
{
	Car theCarTmp = PointerPark->kolvo[aLeftIndex];
	PointerPark->kolvo[aLeftIndex] = PointerPark->kolvo[aRightIndex];
	PointerPark->kolvo[aRightIndex] = theCarTmp;
}

char *mediana(Park *PointerPark, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;
	
	if (1 == strcmp(PointerPark->kolvo[aLeftIndex].Name , PointerPark->kolvo[theCenter].Name))
	{
		swap(PointerPark, aLeftIndex, theCenter);
	}

	if (1 == strcmp(PointerPark->kolvo[aLeftIndex].Name , PointerPark->kolvo[aRightIndex].Name))
	{
		swap(PointerPark, aLeftIndex, aRightIndex);
	}

	if (1 == strcmp(PointerPark->kolvo[theCenter].Name , PointerPark->kolvo[aRightIndex].Name))
	{
		swap(PointerPark, theCenter, aRightIndex);
	}
	
	swap(PointerPark, theCenter, aRightIndex - 1);
	
	int lenth = strlen(PointerPark->kolvo[aRightIndex - 1].Name)+1;
	char *aPivot = (char *)malloc(sizeof(char)*lenth);
	strcpy(aPivot, PointerPark->kolvo[aRightIndex - 1].Name);
	
	return aPivot;
}

int m_partitionIt(Park *PointerPark, int aLeftIndex, int aRightIndex, char *aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex-1;
	
	while (1)
	{
		// search the bigest element
		while (-1 == strcmp(PointerPark->kolvo[++theLeft].Name , aPivot));
	
		// search the lowest element
		while (1 == strcmp(PointerPark->kolvo[--theRight].Name, aPivot));
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			swap(PointerPark, theLeft, theRight);
		}
	}

	//lets to swap elements
	swap(PointerPark, theLeft, aRightIndex-1);
		
	free(aPivot);
	return theLeft; // return break position
}

void quickSort2(Park *PointerPark, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	if (theSize <= 3)
	{
		m_manualSort(PointerPark, aLeftIndex, aRightIndex);
	}
	else
	{
		char *thePivot = mediana(PointerPark, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(PointerPark, aLeftIndex, aRightIndex, thePivot);
		
		//left part sorting
		quickSort2(PointerPark, aLeftIndex, thePartitionIndex - 1);
		
		//right part sorting
		quickSort2(PointerPark, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(Park *PointerPark, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;
	
	if (theSize <= 1)
	{
		return;
	}
	
	if (2 == theSize)
	{
		if (1 == strcmp(PointerPark->kolvo[aLeftIndex].Name , PointerPark->kolvo[aRightIndex].Name))
		{
			swap(PointerPark, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		// 3 elementes
		if (1 == strcmp(PointerPark->kolvo[aLeftIndex].Name , PointerPark->kolvo[aRightIndex - 1].Name))
		{
			swap(PointerPark, aLeftIndex, aRightIndex - 1);
		}
	
		if (1 == strcmp(PointerPark->kolvo[aLeftIndex].Name , PointerPark->kolvo[aRightIndex].Name))
		{
			swap(PointerPark, aLeftIndex, aRightIndex);
		}

		if (1 == strcmp(PointerPark->kolvo[aRightIndex - 1].Name , PointerPark->kolvo[aRightIndex].Name))
		{
			swap(PointerPark, aRightIndex - 1, aRightIndex);
		}
	}
}

int BinarySearch(Park *PointerPark, char *aName)
{
	int Left = 0;
	int Right = PointerPark->curent - 1;
	int middle = 0;
	int Result = -1;
	
	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if(0==strcmp(PointerPark->kolvo[middle].Name, aName))
		{
			Result = middle;
			break;
		}
		else
		{
			if(1==strcmp(PointerPark->kolvo[middle].Name , aName))
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
