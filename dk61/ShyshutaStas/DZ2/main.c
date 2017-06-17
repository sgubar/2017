#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
int main (int argc, char *argv[])
{
	printf( "enter a nomber of paralelepipeds:");
	int number = scan();//приймає знач з клавіатури
	mylist *List=createMyList(number);// створення  списку
	int i;
    for(i=0; i<number; i++)
    {
    addCoor(List);//записує значення в структури
    }
	printMyFigure(List); //друк значень малюнку
	destroyMyList(List); //видаляємо список (щоб не засоряти пам'ять)
	return 0;
	
}


