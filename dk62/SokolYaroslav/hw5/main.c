#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
	FILE *aFile=fopen("data.json", "w");
    srand(time(NULL));
    printf("Vvedite kolichestvo figur:");
	int Size=scan_f();
	FigureList *List=createFigureList(9999);
	int i;
	for(i=0; i<Size; i++)
    {
    addCoor(List);
    }
    printf("================================\n");
    printf("Do bubleSort:\n");
	printFigure(List);
	quickSort2(List, 0, List->current_size - 1);
	writeList(aFile, List);
	printf("================================\n");
	printf("Posle bubleSort:\n");
	printFigure(List);
	printf("Vvedite S(chotirikytnika) dlya poiska: ");
	int theResult=line_find(List);
    printf("Positiya poiskovoi figuri:%i\n", theResult);
    
	destroyFigureList(List);
	
	
}
