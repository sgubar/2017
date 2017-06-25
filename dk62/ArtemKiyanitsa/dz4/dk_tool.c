#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

void AddKoleso (Car *PointerCar,char *InputPokrishka,char InputDisk[10])
{
	if (NULL != PointerCar)
	{
		if(PointerCar->curent<PointerCar->max)//proveryaem nalichie mesta dlya kolesa
		{
			Koleso *theKoleso = &(PointerCar->KolvoKoles[PointerCar->curent]);//sozdaem ukazatel na koleso kotoroe dobavlyaem
			theKoleso->pokrishka = (char *)malloc(sizeof(char)*(strlen(InputPokrishka)+1));//rezerviruem mesto pod pokrishku
			strcpy(theKoleso->pokrishka, InputPokrishka);
			strcpy(theKoleso->disk, InputDisk);
			PointerCar->curent++;
		}
	}
}

void DeleteKoleso (Car *PointerCar)
{
	if (NULL != PointerCar)
	{
		if(PointerCar->curent != 0)
		{
			Koleso theKoleso = PointerCar->KolvoKoles[PointerCar->curent-1];//sodaem ukazatel na poslednee koleso
				if (NULL != theKoleso.pokrishka)
				{
					free(theKoleso.pokrishka);//chistim znachenie pokrishkaishki v poslednem kolese
					PointerCar->curent--;
				}
		}
	}
}
void DeleteCar(Car *PointerCar)
{
	if (NULL != PointerCar)
		{
			if(NULL != PointerCar->KolvoKoles)
			{
				int i;
				for (i = 0; i < PointerCar->curent; i++)//sozdaem ukazatel na kolesa esli oni est nachinaya s poslednego
				{
					Koleso theKoleso = PointerCar->KolvoKoles[i];
					if (NULL != theKoleso.pokrishka)
					{
						free(theKoleso.pokrishka);//chistim znachenie pokrishkaishki v poslednem kolese
					}
				}
				
				free(PointerCar->KolvoKoles);//udalyaem kolesa
			}			
			free(PointerCar);//udalaem mashinu
		}
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

void writeKoleso(FILE *aFile, Koleso *aKoleso)
{
	fprintf (aFile, "{");
	
	writeString(aFile, "pokrishka", aKoleso->pokrishka);
	
	fprintf (aFile, ",");
	fprintf (aFile, "\"disk\":\"%s\"", aKoleso->disk);
	
	fprintf (aFile, "}");
}

void writeCar(FILE *aFile, Car *PointerCar)
{
	fprintf (aFile, "{");
	

	fprintf(aFile, "\"size\":%d", PointerCar->max);
	fprintf(aFile, ",");


	fprintf(aFile, "\"current_size\":%d", PointerCar->curent);
	fprintf(aFile, ",");
	
	fprintf(aFile, "\"kolesa\":");
	
	if (NULL == PointerCar->KolvoKoles)
	{
		fprintf(aFile, "null");
	}
	else
	{
		fprintf(aFile, "[");
		int i;
		for (i = 0; i < PointerCar->curent; i++)
		{
			Koleso *theKoleso = &(PointerCar->KolvoKoles[i]);
		
			writeKoleso(aFile, theKoleso);
		
			if (i < (PointerCar->curent - 1))
			{
				fprintf (aFile, ",");
			}
		}
	
		fprintf(aFile, "]");
	}
	
	fprintf (aFile, "}");
}

void bubbleSortCars(Car *PointerCar, int aSize)
{
	int theOut;
	for (theOut = aSize-1; theOut > 0; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (1 == strcmp(PointerCar->KolvoKoles[theIn].Name, PointerCar->KolvoKoles[theIn + 1].Name))
			{
				Car theTmp = PointerCar->KolvoKoles[theIn];
				PointerCar->KolvoKoles[theIn] = PointerCar->KolvoKoles[theIn + 1];
				PointerCar->KolvoKoles[theIn + 1] = theTmp;
			}
		}
	}
}
