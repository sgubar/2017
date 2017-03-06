#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void) {
	Car *mersedes= (Car *)malloc(sizeof(Car));//sozdaem mashinu
	if(NULL != mersedes)
	{
		mersedes->max = 4;
		mersedes->curent = 0;
		mersedes->kolvo = (Koleso *)malloc(4 * sizeof(Koleso));//zabivaem mesto dlya koles
	}
	
	FILE *theFile = fopen("data.json", "w");
	
	printf("Enter parametrs of koleso\n");
	char *InpPokr=(char *)malloc(sizeof(char)*10);
	printf("(Please enter less than 10 characters) Pokr: ");
	scanf("%s",InpPokr); 
	char InpDisk[10];
	printf("(Please enter less than 10 characters) Disk: ");
	scanf("%s",InpDisk); 
	
	AddKol (mersedes,InpPokr,InpDisk);//dobaliaem koleso
	printf("Koleso added !\n");	
	printf ("%s\n",mersedes->kolvo[mersedes->curent-1].disk);//vivodim znachenie diska poslednego kolesa
	
	
	writeCar(theFile, mersedes);
	
	DeleteKol (mersedes);//udalyaem koleso
	printf("Koleso deleted !\n");
	
	void DelCar(mersedes);//udalyaem mashinu
	
	
	fflush(theFile);
	fclose(theFile);
	
	return 0;	
}
