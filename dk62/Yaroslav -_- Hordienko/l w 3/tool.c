#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"

int BinarySearch(char *String, char toFind)
{
	int Left = 0;
	int Right = strlen(String);
	int middle = 0;
	int Result = -1;

	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if(String[middle] == toFind)
		{
			Result = middle;
			break;
		}
		else
		{
			if(String[middle] > toFind)
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

char *Transform_file_text_to_str (int *InpInt){
	FILE *file = fopen("some_file.txt","r");
	if(file == NULL)
	{
		printf("File don't open some_file.txt\n");
		return 0;
	}
	int Lenth_of_File=0;
	while(fgetc(file)!=EOF)
	{
		Lenth_of_File++;
	}

	printf("Lenth_of_File: %i\n",Lenth_of_File);

	char *String = (char *)malloc(sizeof(char)*(Lenth_of_File));

	fseek(file, 0L, SEEK_SET);
	int i = 0;
	int Proverka_na_n;
	do
	{
		Proverka_na_n=fgetc(file);
		if(Proverka_na_n!='\n'){
			String[i]=Proverka_na_n;
			i++;
		}
	}while(Proverka_na_n!=EOF);
	fclose(file);
	*InpInt = i-2;
	return String;
}

void Print_To_File (int Lenth_of_Str,char *PStr){
	FILE *file = fopen("After_Sort.txt","w");
	int i = 0;
	while(i<Lenth_of_Str){
		fputc((int)PStr[i],file);
		i++;
	}
	fclose(file);
}

void swap(char *anArray, int aLeftIndex, int aRightIndex)
{
	char theTmp = anArray[aLeftIndex];
	anArray[aLeftIndex] = anArray[aRightIndex];
	anArray[aRightIndex] = theTmp;
}

char mediana(char *anArray, int aLeftIndex, int aRightIndex)
{
	int theCenter = (aLeftIndex + aRightIndex) / 2;

	if (anArray[aLeftIndex] > anArray[theCenter])
	{
		swap(anArray, aLeftIndex, theCenter);
	}

	if (anArray[aLeftIndex] > anArray[aRightIndex])
	{
		swap(anArray, aLeftIndex, aRightIndex);
	}

	if (anArray[theCenter] > anArray[aRightIndex])
	{
		swap(anArray, theCenter, aRightIndex);
	}

	swap(anArray, theCenter, aRightIndex - 1);

	return anArray[aRightIndex - 1];
}

int m_partitionIt(char *anArray, int aLeftIndex, int aRightIndex, char aPivot)
{
	int theLeft = aLeftIndex;
	int theRight = aRightIndex - 1;

	while (1)
	{
		while (anArray[++theLeft] < aPivot);

		while (anArray[--theRight] > aPivot);

		if (theLeft >= theRight)
		{
			break;
		}
		else
		{
			swap(anArray, theLeft, theRight);
		}
	}

	swap(anArray, theLeft, aRightIndex - 1);

	return theLeft;
}

void quickSort2(char *anArray, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 3)
	{
		m_manualSort(anArray, aLeftIndex, aRightIndex);
	}
	else
	{
		char thePivot = mediana(anArray, aLeftIndex, aRightIndex);
		int thePartitionIndex = m_partitionIt(anArray, aLeftIndex, aRightIndex, thePivot);

		quickSort2(anArray, aLeftIndex, thePartitionIndex - 1);

		quickSort2(anArray, thePartitionIndex + 1, aRightIndex);
	}
}

void m_manualSort(char *anArray, int aLeftIndex, int aRightIndex)
{
	int theSize = aRightIndex - aLeftIndex + 1;

	if (theSize <= 1)
	{
		return;
	}

	if (2 == theSize)
	{
		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}
		return ;
	}
	else
	{
		if (anArray[aLeftIndex] > anArray[aRightIndex - 1])
		{
			swap(anArray, aLeftIndex, aRightIndex - 1);
		}

		if (anArray[aLeftIndex] > anArray[aRightIndex])
		{
			swap(anArray, aLeftIndex, aRightIndex);
		}

		if (anArray[aRightIndex - 1] > anArray[aRightIndex])
		{
			swap(anArray, aRightIndex - 1, aRightIndex);
		}
	}
}
