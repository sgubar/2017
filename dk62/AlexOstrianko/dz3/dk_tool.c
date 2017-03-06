#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

void AddKol (Car *PCar,char *InputPokr,char InputDisk[10])
{
	if (NULL != PCar)
	{
		if(PCar->curent<PCar->max)//proveryaem nalichie mesta dlya kolesa
		{
			Koleso *theKol = &(PCar->kolvo[PCar->curent]);//sozdaem ukazatel na koleso kotoroe dobavlyaem
			theKol->pokr = (char *)malloc(sizeof(char)*(strlen(InputPokr)+1));//rezerviruem mesto pod pokrishku
			strcpy(theKol->pokr, InputPokr);
			strcpy(theKol->disk, InputDisk);
			PCar->curent++;
		}
	}
}

void DeleteKol (Car *PCar)
{
	if (NULL != PCar)
	{
		if(PCar->curent != 0)
		{
			Koleso theKol = PCar->kolvo[PCar->curent-1];//sodaem ukazatel na poslednee koleso
				if (NULL != theKol.pokr)
				{
					free(theKol.pokr);//chistim znachenie pokrishki v poslednem kolese
					PCar->curent--;
				}
		}
	}
}

void DelCar(Car *PCar)
{
	if (NULL != PCar)
		{
			if(NULL != PCar->kolvo)
			{
				int i;
				for (i = 0; i < PCar->curent; i++)//sozdaem ukazatel na kolesa esli oni est\ nachinaya s poslednego
				{
					Koleso theKol = PCar->kolvo[i];
					if (NULL != theKol.pokr)
					{
						free(theKol.pokr);//chistim znachenie pokrishki v poslednem kolese
					}
				}
				
				free(PCar->kolvo);//udalyaem kolesa
			}			
			free(PCar);//udalaem mashinu
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
