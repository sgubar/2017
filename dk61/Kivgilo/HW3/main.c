#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

int main(void)
{   
    FILE *aFile=fopen("data.json", "w");
    printf("Enter a quantity of Figure (not more 10):");
	int Size=scan_f();
	List_of_Figure *List=createList_of_Figure(10);
	int i;
	for(i=0; i<Size; i++)
    {
    WriteCoordinate(List);
    }
	printFigure(List);
	writeList(aFile, List);
	
	destroyList_of_Figure(List);
	
}
