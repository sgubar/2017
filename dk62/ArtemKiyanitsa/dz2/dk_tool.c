#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

void AddKoleso (Car *PointerCar,char *InputPokrishka,char InputDisk[10])
{
	if (NULL != PointerCar)
	{
		if(PointerCar->curent<PointerCar->max)//proveryaem nalichie mesta dlya kolesa
		{
			Koleso *theKoleso = &(PointerCar->kolvo[PointerCar->curent]);//sozdaem ukazatel na koleso kotoroe dobavlyaem
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
			Koleso theKoleso = PointerCar->kolvo[PointerCar->curent-1];//sodaem ukazatel na poslednee koleso
				if (NULL != theKoleso.pokrishka)
				{
					free(theKoleso.pokrishka);//chistim znachenie pokrishkaishki v poslednem kolese
					PointerCar->curent--;
				}
		}
	}
}
void DeletesCar(Car *PointerCar)
{
	if (NULL != PointerCar)
		{
			if(NULL != PointerCar->kolvo)
			{
				int i;
				for (i = 0; i < PointerCar->curent; i++)//sozdaem ukazatel na kolesa esli oni est nachinaya s poslednego
				{
					Koleso theKoleso = PointerCar->kolvo[i];
					if (NULL != theKoleso.pokrishka)
					{
						free(theKoleso.pokrishka);//chistim znachenie pokrishkaishki v poslednem kolese
					}
				}
				
				free(PointerCar->kolvo);//udalyaem kolesa
			}			
			free(PointerCar);//udalaem mashinu
		}
}
