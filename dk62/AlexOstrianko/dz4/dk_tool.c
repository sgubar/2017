#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void AddKol (Car *PCar)
{	
	printf("Enter parametrs of koleso\n");
	char InpPokr[10];
	printf("(Please enter less than 10 characters) Pokr: ");
	scanf("%s",InpPokr); 
	char InpDisk[10];
	printf("(Please enter less than 10 characters) Disk: ");
	scanf("%s",InpDisk); 
	
	if (NULL != PCar)
	{
		if(PCar->curent<PCar->max)//proveryaem nalichie mesta dlya kolesa
		{
			Koleso *theKol = &(PCar->kolvo[PCar->curent]);//sozdaem ukazatel na koleso kotoroe dobavlyaem
			strcpy(theKol->pokr, InpPokr);
			strcpy(theKol->disk, InpDisk);
			PCar->curent++;
		}
	}
	free(InpPokr);
}

void Vivod (Garaj *PGar){
	int i =0;
	while(i<PGar->curent)
	{
		printf("%s\n",PGar->kolvo[i].Name);
		i++;
	}
}

void DeleteKol (Car *PCar)
{
	if (NULL != PCar)
	{
		if(PCar->curent != 0)
		{
			PCar->curent--;
		}
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

void sortCars(Garaj *PGar)
{
	int theOut;
	for (theOut = 0; theOut < PGar->curent - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;	
		for (theIn = theOut + 1;theIn < PGar->curent; theIn ++)
		{
			if (-1 == strcmp(PGar->kolvo[theIn].Name,PGar->kolvo[theMinIndex].Name))
			{
				theMinIndex = theIn;
			}
		}
	
		Car theTmp = PGar->kolvo[theOut];
		PGar->kolvo[theOut] = PGar->kolvo[theMinIndex];
		PGar->kolvo[theMinIndex] = theTmp;
	}
}

void bubbleSortCars(Garaj *PGar, int aSize)
{
	int theOut;
	for (theOut = aSize-1; theOut > 0; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (1 == strcmp(PGar->kolvo[theIn].Name, PGar->kolvo[theIn + 1].Name))
			{
				Car theTmp = PGar->kolvo[theIn];
				PGar->kolvo[theIn] = PGar->kolvo[theIn + 1];
				PGar->kolvo[theIn + 1] = theTmp;
			}
		}
	}
}

void insertionSort(Garaj *PGar, int aSize)
{
	int theOut;
	for (theOut = 1; theOut < aSize; theOut ++)
	{
		Car theTmp = PGar->kolvo[theOut];
		int theIn = theOut;
		while (theIn > 0 && (-1 != strcmp(PGar->kolvo[theIn - 1].Name, theTmp.Name)))
		{
			PGar->kolvo[theIn] = PGar->kolvo[theIn - 1];
			-- theIn;
		}	
			PGar->kolvo[theIn] = theTmp;
	}
}

void writeKol(FILE *aFile, Koleso *aKol)
{
	fprintf (aFile, "{");
	
	writeString(aFile, "pokrishka", aKol->pokr);
	
	fprintf (aFile, ",");
	fprintf (aFile, "\"disk\":\"%s\"", aKol->disk);
	
	fprintf (aFile, "}");
}

void writeCar(FILE *aFile, Car *PCar)
{
	fprintf (aFile, "{");
	
	//	"size" : 10,
	fprintf(aFile, "\"size\":%d", PCar->max);
	fprintf(aFile, ",");

	//	"current_size" : 2
	fprintf(aFile, "\"current_size\":%d", PCar->curent);
	fprintf(aFile, ",");
	
	fprintf(aFile, "\"kolesa\":");
	
	if (NULL == PCar->kolvo)
	{
		fprintf(aFile, "null");
	}
	else
	{
		fprintf(aFile, "[");
		int i;
		for (i = 0; i < PCar->curent; i++)
		{
			Car *theKol = &(PCar->kolvo[i]);
		
			writeKol(aFile, theKol);
		
			if (i < (PCar->curent - 1))
			{
				fprintf (aFile, ",");
			}
		}
	
		fprintf(aFile, "]");
	}
	
	fprintf (aFile, "}");
}

void writeString(FILE *aFile, char *aKey, char *aString)
{
	fprintf(aFile, "\"%s\":", aKey);
	
	if (NULL == aString)
	{
		fprintf (aFile, "null");
	}
	else
	{
		fprintf (aFile, "\"%s\"", aString);
	}
}
