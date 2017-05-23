#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, const char *argv[])
{
	int a = 0;
	do{										//цикл будет выполняться, пока a < 1
		printf("Enter number of circles: ");
		scanf("%i", &a);
	}while(a < 1);
	
	list *circ = createList(a);				//выделяет память на нужное количество кругов
	
	while(a != 0)							//цикл
	{
		newCoordinate(circ);
		a--;
	}
	
	printArea(circ);						//выводит на экран
	printJson(circ);						//выводит в файл
	destroyList(circ);
	
	return 0;
}
