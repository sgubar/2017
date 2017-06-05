#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
	FILE * file = fopen("data.json", "w");
    printf("Hello. Programm won't work if you create more then 10 triangles \n");
    printf("How many triangles to create? : ");
	
	
	int Size;
	int check = scanf("%i", &Size);
	
	while (Size > 10 || check == 0)
		{
		printf("\nInncorect value. \n");
		return 0;
		}
	
		while (Size <= 10)
		{
		FigureList *List=createFigureList(10);
		
		int i;
		for(i=0; i<Size; i++)
   			 {
    		FillCoord(List);
    		 }
    	printf("\n	- - - - - - - List of triangles before sorting - - - - - - -\n\n");
    	fprintf(file, "	- - - - - - - List of triangles before sorting - - - - - - -\n\n");
		WriteToFile_List(file, List);
		SelectionSort(List);
		printf("\n	- - - - - - - List of triangles after sorting - - - - - - -\n\n");
		fprintf(file, "	- - - - - - - List of triangles after sorting - - - - - - -\n\n");
		WriteToFile_List(file, List);
		return 0;
		}
	fclose(file);		
	return 0;
}

