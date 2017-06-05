#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#include "dk_tool.h"


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
	printf("\n\nPlease choose your type of sorting:\n1 - bubbleSort,\n2 - selectionSort,\n3 - insertionSort,\n4 - ShellSort.\n");
	int caseCounter;
	float startBubbleS, stopBubbleS;
	float startSelectionS, stopSelectionS;
	float startInsertionS, stopInsertionS;
	float startShellS, stopShellS;
	
	while(1)
	{
		caseCounter = NumInput();
		
		if (caseCounter > 0 && caseCounter < 5)
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
			
		case 4:
			startShellS = clock();
			shellSort(anArray, aSize);
			stopShellS = clock();
			
			float shellSortingTime = (float) (stopShellS - startShellS) / CLOCKS_PER_SEC;
			
			printf("\nSuccessfully sorted by shellSort. Time of sorting: %.15f\n", shellSortingTime);
			fprintf(ptrFile, "Successfully sorted by shellSort. Time of sorting: %.10f.\n\nYour array after sorting: \n\n\n", shellSortingTime);
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


void shellSort(char *anArray, int aSize)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= aSize/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aSize; theOuter ++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}
		
			anArray[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
}

int binarySearch(char *anArray, int aSize, char searchLetter)
{
    int low, high, middle;
    low = 0;
    high = aSize - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (searchLetter == anArray[middle])
            return middle;
        else if (searchLetter > anArray[middle])
            low = middle + 1;
        else 
        	high = middle - 1;
    }
    return -1;
}

int searchFunction(char *anArray, int aSize)
{
	float startBinaryS, stopBinaryS;

	char searchLetter;	
    printf("Enter a letter which you want to search: ");
    searchLetter = letterInput();

	startBinaryS = clock();
	int searchLetterIndex = binarySearch(anArray, aSize, searchLetter);
	stopBinaryS = clock();
	
	float binarySearchingTime = (float) (stopBinaryS - startBinaryS) / CLOCKS_PER_SEC;
	printf("\n\nTime of searching by binary search: %.15f\n", binarySearchingTime);
	
	if(searchLetterIndex == -1)
	{
		printf("\nYour letter is not found.");
		return 1;
	}
		
	printf("\nYour letter index in anArray is [%d]", searchLetterIndex);
	
	return 0;
}


char letterInput(void)
{
	char letter;
	while(1)
	{
	    letter = getche();       
	    if (isalpha(letter))
		{
			break;	
		}                           
	    else 
	    {
		    printf("\nPlease enter another letter:\n");
		    fflush(stdin);
		}
    }
	return letter;
}


int NumInput()
{
	int Num;
	int Proof;							
	while(1)
	{						
		Proof = scanf("%d", &Num);
		if (Proof == 1)		 		
		{
			break;
		}
		printf("Please enter another number:\n");
		fflush (stdin); 				
	}
	return Num;
}



