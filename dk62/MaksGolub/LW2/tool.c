#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"


int LengthFile(FILE *aFile) //counting length of file;
{
	
	int length=0;
	while(fgetc(aFile)!=EOF)
	{		
		length++;
	}	
	printf("length: %i\n", length);
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
	printf("Time selection sorting: %0.10lf\n", ptr/CLOCKS_PER_SEC);
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
	printf("Time bubble sorting: %0.10lf\n", ptr/CLOCKS_PER_SEC);
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
	printf("Time insertion sorting: %0.10lf\n", ptr/CLOCKS_PER_SEC);
}

void PrintFile (int Length, char *MasFile) //print result in file;
{
	FILE *file = fopen("data2.txt","w");
	int i = 0;
	while(i<Length)
	{		
		putc((int)MasFile[i],file);
		i++;
	}
	fclose(file);
}
