#include "find_tools.h"
#include "area_tools.h"

#include<stdio.h>
#include<stdlib.h>

int line_find(SquareArray *anArray)
{
	printf("\n\ngive me your key for searching = ");
	float aKey = scan(-100000, 1000000);
	
	int aSize = anArray->current_size;
	
	int position = INT_MAX;
	
	int i = 0;
	for (i ; i < aSize; i++)
	{
		if (anArray->array[i].area == aKey)
		{
			position = i;
			break;
		}
	}
	
	if (position == INT_MAX)
	{
		printf("\nthere isn't your key in an array\n\n");
	}
	else
	{
	printf("\nyour key is in an array and it stays at %i position\n", position);
	}
	return position;
}
