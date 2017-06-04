#include <stdio.h>
#include "dk_tool.h"
#include "sort.h"
#include "binSearch.h"


int main() 
{
	FILE * ptrFile = fopen("aPyramidsList.json", "w");
	
	printf("Max count of pyramids:\n");
	
	int aSize = NumInput();					 
	if(aSize < 1 || aSize > 100000000)
	{
		return 1;
	}
	
	pyramidsList *aPyramidsList = createPyramidsList(aSize);		
	
	int i;
	for(i = 0; i < aSize; i++)
	{
			addPyramid(aPyramidsList);
	}	
	
	// выводим наши пирамиды и площади, пишем в файл
	printPyramidsList(aPyramidsList);
	FilePrintPyramidsList(ptrFile, aPyramidsList);

	printSquare(aPyramidsList);
	FilePrintSquare(ptrFile, aPyramidsList);
	
	//сортируем
	sortType(ptrFile, aPyramidsList);
	
	//выводим на экран площади после сортировки
	printf("\n\nAfter sorting: \n");
	printSquare(aPyramidsList);
	
	//пишем в файл площади после сортировки
	fprintf(ptrFile, " \n\n\nAfter sorting: \n");
	FilePrintSquare(ptrFile, aPyramidsList);

	//ищем нужное значение площади
	searchFunction(aPyramidsList);
	
	destroyAPyramidsList(aPyramidsList);
	
	fflush (ptrFile);
	fclose (ptrFile);
	
	return 0;
}
