#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"



//  addCoor бісить користувача користувача  кучою значень які тре ввести!!!!
//краще щоб значення вводились без втручання користувача (((наприклад перші 2  рамдомні  а всі інші паралельно але теж рамдомом)))!!!!
//чому пише файл не відкомпільовано але все працює ?



int main(void)
{   
    FILE *aFile=fopen("data.json", "w");// відкриває файл 
    printf("Enter a nomber of Figure :");
	int Size = scan();
	mylist *List=createMyList(Size);//виділяє память 
	int i;
	for(i=0; i<Size; i++)
    {
    addCoor(List); //кординати точок
    }
	printMyFigure(List); //друк значень малюнку 
    selectionSort(List); //вибір сортування
	printMyFigure(List);//друк відсортованих значень малюнку
	writeMyList(aFile, List);
	destroyMyList(List);
	fflush(aFile);
	fclose(aFile);
}
