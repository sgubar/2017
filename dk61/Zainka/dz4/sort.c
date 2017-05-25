#include <stdio.h>
#include "sort.h"
#include "dk_tool.h"

void Bubble_Sort_List(filepiramida *polochka)
{
	int i, j, result;
	for (i = 1; i < polochka->current_size; i++)
	{
		result = 0; 						
		for (j = 1; j < polochka->current_size - i + 1; j++)
		{
			if (area(&polochka->Piramida[j]) > area(&polochka->Piramida[j - 1]))
			{
				swap(&polochka->Piramida[j], &polochka->Piramida[j - 1]);
				result++; 					
			}
		}
		if (!result)
			break;
	}
}
