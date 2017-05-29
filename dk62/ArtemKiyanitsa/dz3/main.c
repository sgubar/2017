#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void) 
{
	FILE *theFile= fopen("kek.json", "w");
	int i=1;
	int KolvoKoles;
	Car *theCar= (Car *)malloc(sizeof(Car));//create car
	if(NULL != theCar)
	{
		theCar->max = 4;
		theCar->curent = 0;
		theCar->KolvoKoles = (Koleso *)malloc(4 * sizeof(Koleso));// space dlya koles
	}
	do
	{
	printf("Enter kol-vo koles:");
	scanf ("%i", &KolvoKoles);
	}
	while (KolvoKoles<0 || KolvoKoles>theCar->max);	
	char *InputPokrishka=(char *)malloc(sizeof(char)*10);
	char InpDisk[10];
	while (i<= KolvoKoles)
	{	printf("---------Koleso: # %i\n",i);
		printf("Parametr Pokrishki: ");
		scanf("%s",InputPokrishka); 
		printf("Parametr Diska: ");
		scanf("%s",InpDisk); 
		
		AddKoleso (theCar,InputPokrishka,InpDisk);//add koleso
		printf("Koleso added !\n");	
		printf ("Parametr Diska: %s\n",theCar->KolvoKoles[theCar->curent-1].disk); //vivodim znachenie diska kolesa
		i++;
	
	}
	writeCar (theFile, theCar);
	i=1;
	while (i<= KolvoKoles)
	{
		printf("---------Koleso: # %i\n",i);
		DeleteKoleso (theCar);		//delete koleso
		printf("Koleso %i deleted !\n",i);
		i++;
		
	}

	DeleteCar(theCar);//delete car
	
	return 0;	
	fclose (theFile);
}
