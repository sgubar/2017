#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
    printf("Hello. Programm won't work if you create more then 10 triangles \n");
    printf("How many triangles to create? : ");
	
	
	int Size;
	int check = scanf("%i", &Size);
	
	if (check != 0)
	{
	while (Size > 10)
		{
		printf("Inncorect value. \n");
		printf("Try again : ");
		scanf("%i", &Size);
		}
	
		while (Size <= 10)
		{
		FigureList *List=createFigureList(10);
		
		int i;
		for(i=0; i<Size; i++)
   			 {
    		addCoor(List);
    		 }
		printFigure(List);
		return 0;
		}
	}
	else {
		printf("PRINT ONLY A NUBMER!!!\n");
	}
	return 0;
}
