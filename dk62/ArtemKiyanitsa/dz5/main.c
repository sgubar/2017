#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"


int main(void) 
{
	Park *PointerPark = CreatePark(5);
	
	char *Name=(char *)malloc(10*sizeof(char));
		
	strcpy(Name, "lol");
	AddCar(PointerPark,Name);
	
	strcpy(Name, "koronniy");
	AddCar(PointerPark,Name);
	
	strcpy(Name, "kek");
	AddCar(PointerPark,Name);
	
	strcpy(Name, "pohoronniy");
	AddCar(PointerPark,Name);
	
	strcpy(Name, "lmao");
	AddCar(PointerPark,Name);
	
	quickSort2(PointerPark, 0 ,  PointerPark->curent-1);
	if(-1 != BinarySearch(PointerPark,"kek"))
		printf("\nCar #kek on the %i place\n",BinarySearch(PointerPark,"kek")+1);
	else
		printf("\nCar #kek not found\n");
			
	printf("\nSorted:\n\n");
	Print(PointerPark);
	
	DeletePark(PointerPark);
	free(Name);
	return 0;	
}
