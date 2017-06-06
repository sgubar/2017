#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");     
    FILE *aFile=fopen("data.json", "w");
    printf("Ââåäèòå êîëè÷åñòâî ôèãóð (!>10):");
	int Size=scan_f();
	List_of_Figure *List=createList_of_Figure(10);
	int i;
	for(i=0; i<Size; i++)
    {
    WriteCoordinate(List);
    }
    selectionSort(List);
	printFigure(List);
	writeList(aFile, List);
	
	destroyList_of_Figure(List);
	
}
