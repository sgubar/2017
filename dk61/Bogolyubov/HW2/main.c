#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
    printf("Value of squares (max 7) : ");
	
	
	int Size;
	int check = scanf("%i", &Size); //proverka na bukvi (esli bukva = scanf vidaet 0)
	
	if (check != 0)
	{
		
		PtsList *List=createPtsList(7); //sozdanie spiska
		
		int i;
		for(i=0; i<Size; i++)
   			 {
    		fillList(List);
    		 }
		printPts(List);
		return 0;
	}
	else {
		printf("ERROR (incorrect symbol)\n");
	}
	return 0;
}
