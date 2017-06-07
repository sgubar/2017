/*спочатку відсортував за допомогою швидкого сортування
потім за допомогою бінарного пошуку знайшов площу яку просить користувач*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"

int main(void)
{   
    FILE *aFile=fopen("data.json", "w"); //сворюємо і відкриваємо файл 
    printf("Enter a nomber of Figure :");
	int Size=scan();//кількість малюнків
	FigureList *List=createFigureList(Size); //виділяє память і очищує її
	int i;
    for(i=0; i<Size; i++)
    {
    addCoor(List);//додаєм координати малюнків
    }
    printFigure(List); //  друкуємо малюнок 
    quickSort(List, 0, List->current_size - 1); //сортування quickSort
    printf("After sorting \n");
	printFigure(List); 
	printf("Enter square for searching: ");
	int result = BinarySearch(List); //бінарний пошук
	printf("Position of figure: %d", result);
	destroyFigureList(List);
	
}
