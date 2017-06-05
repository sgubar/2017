#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <time.h>
#include "dk_tool.h"

int NumInput()
{
	int Num;
	int Proof;							
	while(1)
	{						
		Proof = scanf("%d", &Num);
		if ( Proof == 1)		 		
			{
				break;
			}
		printf("Please enter another number:\n");
		fflush (stdin); 				
	}
	return Num;
}


void fillingArrayFunction(char *anArray, int aSize)
{
	srand(time(NULL));
 	
	int j, i, k;
	
	char alphabetArray[53];
	for (j = 0; j < 26; j++)
	{
		alphabetArray[j] = j + 65;		
	}
	
	for (i = 26; i < 52; i++)
	{
		alphabetArray[i] = tolower(alphabetArray[i - 26]);	
	}	

    	for (k = 0; k < aSize; k++)
   	{	
		int randomIndex = 0 + rand() % 52;
    		anArray[k] = alphabetArray[randomIndex];
	}
}


void fileWrite(FILE *ptrFile, char *anArray, int aSize)
{
	int i;
	
	for(i = 0; i < aSize; i++)
	{
		fprintf(ptrFile, "%c", anArray[i]);
	}

}
	



void sortType(FILE *ptrFile, char *anArray, int aSize)
{
	printf("\n\nPlease choose your type of sorting:\n1 - bubbleSort,\n2 - selectionSort,\n3 - insertionSort.\n");
	int caseCounter;
	float startBubbleS, stopBubbleS;
	float startSelectionS, stopSelectionS;
	float startInsertionS, stopInsertionS;
	
	while(1)
	{
		caseCounter = NumInput();
		
		if (caseCounter > 0 && caseCounter < 4)
			break;
			
		printf("\nPlease enter another number:\n");
		fflush (stdin); 
	}	
	
	switch (caseCounter) 
	{
		case 1:
			startBubbleS = clock();
			bubbleSort(anArray, aSize);
			stopBubbleS = clock();
			
			float bubbleSortingTime = (float) (stopBubbleS - startBubbleS) / CLOCKS_PER_SEC;
			
			printf("\nSuccessfully sorted by bubbleSort. Time of sorting: %.15f\n", bubbleSortingTime);
			fprintf(ptrFile, "Successfully sorted by bubbleSort. Time of sorting: %.10f.\n\nYour array after sorting: \n\n\n", bubbleSortingTime);
			break;
			
		case 2:
			startSelectionS = clock();
			selectionSort(anArray, aSize);
			stopSelectionS = clock();
			
			float selectionSortingTime = (float) (stopSelectionS - startSelectionS) / CLOCKS_PER_SEC;
			
			printf("\nSuccessfully sorted by selectionSort. Time of sorting: %.15f\n", selectionSortingTime);
			fprintf(ptrFile, "Successfully sorted by selectionSort. Time of sorting: %.10f.\n\nYour array after sorting: \n\n\n", selectionSortingTime);
			break;
			
		case 3:
			startInsertionS = clock();
			insertionSort(anArray, aSize);
			stopInsertionS = clock();
			
			float insertionSortingTime = (float) (stopInsertionS - startInsertionS) / CLOCKS_PER_SEC;
			
			printf("\nSuccessfully sorted by insertionSort. Time of sorting: %.15f\n", insertionSortingTime);
			fprintf(ptrFile, "Successfully sorted by insertionSort. Time of sorting: %.10f.\n\nYour array after sorting: \n\n\n", insertionSortingTime);
			break;		
	}
}


void bubbleSort(char *anArray, int aSize)
{
	int theOut = aSize - 1;

	for (theOut; theOut > 1; theOut --)
	{
		int theIn = 0;

		for (theIn; theIn < theOut; theIn ++)
		{
			if (anArray[theIn] > anArray[theIn + 1])
			{
				int theTmp = anArray[theIn];
				anArray[theIn] = anArray[theIn + 1];
				anArray[theIn + 1] = theTmp;
			}
		}
	}
}


void selectionSort(char *anArray, int aSize)
{
		int theOut = 0;
	for (theOut; theOut < aSize - 1; theOut ++)
	{
		int theMinIndex = theOut;

		int theIn = theOut + 1;
		for (theIn; theIn < aSize; theIn ++)
		{
			if (anArray[theIn] < anArray[theMinIndex])
			{
				theMinIndex = theIn;
			}
		}

		int theTmp = anArray[theOut];
		anArray[theOut] = anArray[theMinIndex];
		anArray[theMinIndex] = theTmp;
	}
}


void insertionSort(char *anArray, int aSize)
{
	int theOut = 1;
	for (theOut; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;

		while (theIn > 0 && anArray[theIn - 1] >= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}

		anArray[theIn] = theTmp;
	}
}
