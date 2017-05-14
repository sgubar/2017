#include "find_tools.h"
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
 
int line_find(int anArray[], int aSize, int aKey)
{
	int position = INT_MAX;
	
	int i = 0;
	for (i ; i < aSize; i++)
	{
		if (anArray[i] == aKey)
		{
			position = i;
			break;
		}
	}
	
	if (position == INT_MAX)
	{
		printf("\nthere isn't your key in an array");
	}
	else
	{
	printf("\nyour key is in an array and it stays at %i position", position);
	}
	return position;
}
