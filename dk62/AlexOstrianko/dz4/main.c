#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void) {	
	Garaj *PGar = CreateGaraj(3);
	
	char Name[10];
		
	scanf("%s",Name);
	AddCar(PGar,Name);
	
	scanf("%s",Name);
	AddCar(PGar,Name);
	
	scanf("%s",Name);
	AddCar(PGar,Name);
	
	//sortCars(PGar);
	//bubbleSortCars(PGar,PGar->curent);
	insertionSort(PGar,PGar->curent);
	
	printf("%s\n",PGar->kolvo[0].Name);	
	printf("%s\n",PGar->kolvo[1].Name);
	printf("%s\n",PGar->kolvo[2].Name);
	
	DelGar(PGar);//udalyaem garaj
	return 0;	
}
