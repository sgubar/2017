#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"


int LengthFile(FILE *aFile) //counting length of file;
{
	
	fseek (aFile, 0, SEEK_END);
    int length = ftell(aFile);
	printf("Количество символов: %d\n", length);
	
	return length;
	
}


char *StrFile(FILE *aFile, int length) //create mass for symboll;
{	

	char *Str = (char *)malloc(sizeof(char)*length);	
    int i = 0;
	int point;
	fseek(aFile, 0, SEEK_SET);	
	while((point=fgetc(aFile)) !=EOF) 
	{
      Str[i]=(char)point;
      i++;
    }  
    
    return Str;	
}

void selectionSort(int length , char *MasFile)
{
	int theOut;	
	clock_t begin = clock();
	for (theOut = 0; theOut < length - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;	
		for (theIn = theOut + 1;theIn < length; theIn ++)
		{
			if (MasFile[theIn]<MasFile[theMinIndex])
			{				
				theMinIndex = theIn;
			}
		}
	
		char theTmp = MasFile[theOut];
		MasFile[theOut] = MasFile[theMinIndex];
		MasFile[theMinIndex] = theTmp;
	}
	clock_t end = clock();
	double ptr = end - begin; 
	printf("Время затраченное на сортировку selection: %0.10lf\n", ptr/CLOCKS_PER_SEC);
}

void bubbleSort(int length, char *MasFile)
{
	int theOut;
	clock_t begin = clock();
	for (theOut = length-1; theOut > 0; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (MasFile[theIn] < MasFile[theIn + 1])
			{
				char theTmp = MasFile[theIn];
				MasFile[theIn] = MasFile[theIn + 1];
				MasFile[theIn + 1] = theTmp;
			}
		}
	}
	clock_t end = clock();
	double ptr = end - begin; 
	printf("Время затраченное на сортировку bubble: %0.10lf\n", ptr/CLOCKS_PER_SEC);
}

void insertionSort(int length, char *MasFile)
{
	int theOut;
	clock_t begin = clock();
	for (theOut = 1; theOut < length; theOut ++)
	{
		char theTmp = MasFile[theOut];
		int theIn = theOut;
		while (theIn > 0 && (MasFile[theIn-1] >= theTmp))
		{
			MasFile[theIn] = MasFile[theIn - 1];
			-- theIn;
		}	
			MasFile[theIn] = theTmp;
	}
	clock_t end = clock();
	double ptr = end - begin; 
	printf("Время затраченное на сортировку insertion: %0.10lf\n", ptr/CLOCKS_PER_SEC);
}

void shellSort(int length, char *MasFile)
{
	clock_t begin = clock();
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; 
	
	
	while (theH <= length/3)
	{
		theH = theH*3 + 1; 
	}

	while (theH > 0)
	{
		for (theOuter = theH; theOuter < length; theOuter ++)
		{
			int theTmp = MasFile[theOuter];
			theInner = theOuter;
		
			while (theInner > theH-1 &&  MasFile[theInner - theH] >= theTmp)
			{
				 MasFile[theInner] =  MasFile[theInner - theH];
				theInner =theInner - theH;
			}
		
			 MasFile[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; 
	}
	clock_t end = clock();
	double ptr = end - begin; 
	printf("Время затраченное на сортировку shell: %0.10lf\n", ptr/CLOCKS_PER_SEC);
}

void PrintFile (int Length, char *MasFile) //print result in file;
{
	FILE *file = fopen("data1.txt","w");
	int i = 0;
	while(i<Length)
	{		
		putc((int)MasFile[i],file);
		i++;
	}
	fclose(file);
}

int BinarySearch(int length, char *MasFile, char find)
{
	int Left = 0;
	int Right = length;
	int middle = 0;
	int Result = -1;
	clock_t begin = clock();
	while(Left < Right)
	{
		middle = (Left + Right)/2;
		if(MasFile[middle] == find)
		{
			Result = middle;
			break;
		}
		else
		{
			if(MasFile[middle] > find)
			{
				Right = middle - 1;
			}
			else
			{
				Left = middle + 1;
			}
		}
	}
	clock_t end = clock();
	double ptr = end - begin; 
	printf("Время затраченное на сорировку binary : %0.10lf\n", ptr/CLOCKS_PER_SEC);
	return Result;	
}
