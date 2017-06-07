#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
	FILE * file = fopen("storage.json", "w");
    printf("How many squares to create?(max 7) : ");
	
	
	int Size;
	int check = scanf("%i", &Size);
	
	while (Size > 7 || check == 0)
		{
		printf("Inncorect value.");
		return 0;
		}
	
		while (Size <= 7)
		{
		FigureList *List=createFigureList(7);
		
		int i;
		for(i=0; i<Size; i++)
   			 {
    		FillCoord(List);
    		 }
    	printf("List of squares: \n");
    	fprintf(file, "List of squares: \n");
		WriteToFile_List(file, List);
		SelectionSort(List);
		printf("List of squares after sorting:\n");
		fprintf(file, "List of squares after sorting:\n");
		WriteToFile_List(file, List);
		return 0;
		}
	fclose(file);		
	return 0;
}
