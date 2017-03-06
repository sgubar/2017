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

