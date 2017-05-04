#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "laba3.h"
void swap(char *line, int LeftElem, int RightElem)
{
	int tmp = line[LeftElem];
	line[LeftElem] = line[RightElem];
	line[RightElem] = tmp;
}

int mediana(char *line, int LeftElem, int RightElem)
{
	int theCenter = (LeftElem + RightElem) / 2;
	
	if (line[LeftElem] > line[theCenter])
	{
		swap(line,LeftElem, theCenter);
	}

	if (line[LeftElem] > line[RightElem])
	{
		swap(line, LeftElem, RightElem);
	}

	if (line[theCenter] > line[RightElem])
	{
		swap(line, theCenter, RightElem);
	}
	
	swap(line, theCenter, RightElem - 1);
	
	char aPivot = line[RightElem - 1];
	return aPivot;
}

int partitionIt(char *line, int LeftElem, int RightElem, char aPivot)
{
	int theRight = RightElem-1;
	int theLeft = LeftElem ;
	
	while (1)
	{
		// search the bigest element
		while (line[++theLeft] < aPivot);
	
		// search the lowest element
		while( line[--theRight]>aPivot);
		
	
		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			// swap elements
			swap(line, theLeft, theRight);
		}
	}
}
void additionalsort(char *line, int LeftElem, int RightElem)
{
	int Size = RightElem - LeftElem + 1;
	if (Size <= 1)
	{
		return;
	}
	
	if (2 == Size)
	{
		if (line[LeftElem] > line[RightElem])
		{
			swap(line, LeftElem, RightElem);
		}
		return ;
	}
	else
	{
		// 3 elementes
		if (line[LeftElem] > line[RightElem - 1])
		{
			swap(line, LeftElem, RightElem - 1);
		}
	
		if (line[LeftElem] > line[RightElem])
		{
			swap(line, LeftElem, RightElem);
		}

		if (line[RightElem - 1] > line[RightElem])
		{
			swap(line, RightElem - 1, RightElem);
		}
	}
}

void quickSort(char *line, int LeftElem, int RightElem)
{
	int Size = RightElem- LeftElem + 1;
	if (Size <= 3)
	{
		additionalsort(line, LeftElem, RightElem);
	}
	else
	{
		int Pivot = mediana(line, LeftElem, RightElem);
		int PartitionIndex = partitionIt(line, LeftElem, RightElem, Pivot);
		quickSort(line, LeftElem, PartitionIndex - 1);
		quickSort(line, PartitionIndex + 1, RightElem);
		
	}
	
}

void Print_To_File (int counter,char *string)
{
	FILE *file = fopen("Ffile.txt","w");
	int i = 0;
	while(i<counter)
	{		
		fprintf(file, "%s", string[i]);
		i++;
	}
}
	


int BinarySearch( char* string, char find)
{
	int Left = 0;
	int Right = strlen(string);
	int middle = 0;
	int R = -1;
	
	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if(string[middle] == find)
		{
			R = middle;
		//	return (R);
			break;
			
		}
		else
		{
			if(string[middle] > find)
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1;
			}
		}
	}

	return (R);	
}
