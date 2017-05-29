#include <stdio.h>
#include "sort.h"
#include "dk_tool.h"

void Bubble_Sort_List(filepiramida *polochka)
{
	int i, j, result;
	for (i = 1; i < polochka->current_size; i++) // ïðîõîäèìñÿ ïî ìàñèâó
	{
		result = 0; 						
		for (j = 1; j < polochka->current_size - i + 1; j++)  // íàõ íàéá³ëüøèé
		{
			if (area(&polochka->Piramida[j]) > area(&polochka->Piramida[j - 1])) // ïîð³âíþåìî 1 ñ ïðåä³äóùèì 
			{
				swap(&polochka->Piramida[j], &polochka->Piramida[j - 1]); // çì³íþåìî ¿õ 
				result++; 					
			}
		}
		if (!result)
			break;
	}
}
