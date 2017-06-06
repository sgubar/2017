#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"
#include <locale.h>

	


int main(void)
{ 
	setlocale(LC_ALL, "Rus");  
    
    printf("Ââåäèòå êîëè÷åñòâî ôèãóð (!>10):");
	int Size;
	scanf("%d", &Size);
	List_of_Figure *List=createList_of_Figure(10);
	int i;
	for(i=0; i<Size; i++)
    {
    WriteCoordinate(List);
    }
	printList(List);
	destroyList_of_Figure(List);
	
}
