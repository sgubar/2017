#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void) {	
	Garaj *PGar = CreateGaraj(5);
	
	char *Name=(char *)malloc(10*sizeof(char));
		
	strcpy(Name, "Volvo");
	AddCar(PGar,Name);
	
	strcpy(Name, "Mazda");
	AddCar(PGar,Name);
	
	strcpy(Name, "Mersedes");
	AddCar(PGar,Name);
	
	strcpy(Name, "Jaguar");
	AddCar(PGar,Name);
	
	strcpy(Name, "Porsche");
	AddCar(PGar,Name);
	
	quickSort2(PGar, 0 ,  PGar->curent-1);
	if(-1 != BinarySearch(PGar,"Mersedes"))
		printf("\nMersedes on the %i place\n",BinarySearch(PGar,"Mersedes")+1);
	else
		printf("\nMercedes not found\n");
			
	printf("\nSorted:\n\n");
	Vivod(PGar);
	
	DelGar(PGar);//udalyaem garaj
	free(Name);
	return 0;	
}
