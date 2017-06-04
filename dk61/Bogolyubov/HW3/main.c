#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
FILE * file = fopen("storage.json", "w");
    printf("Give me the numb of squares (max 7) : ");
	
	
	int Size;
	int check = scanf("%i", &Size);
	
	if (check != 0)
	{
		
		PtsList *List=createPtsList(7); //sozdanie spiska
		
		int i;
		for(i=0; i<Size; i++)
   			 {
    		fillList(List);
    		 }
		printPts(List);
		WriteToFile_List(file, List);
		return 0;
	}
	else {
		printf("ERROR (incorrect symbol)\n");
	}

	return 0;
}
