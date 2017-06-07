/*
Варіант 5 
В кільцевому списку видаляти кожен третій елемент, 
поки не залишиться менше трьох. 
Відобразити процес на екрані
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"



int main( void )
{
	
int count = 12;
	
	IntList *theList = CreateIntList();//створюєм список елементів
	if (NULL == theList)
	{
		return -1;
	}

	int z;
	for( z = 0; z < count;  z++)
	{
		AddIntValueToList(theList, rand() % 999);//додаєм значення до списку
	}
	
	DeleteMultiplesElements(theList, 3);//видаляє кожен 3 елемент 
	
	DestroyIntList(theList); //видаляємо список
	return 0;
}

