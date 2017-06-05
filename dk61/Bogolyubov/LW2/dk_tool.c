#include "dk_tool.h"

#include <stdio.h>
#include <string.h>

void bubbleSort(char *str, int lenght)
	{
		for (int i = lenght-1; i > 0; i --)
		{		
			int j;
				for (int j = 0; j < i; j ++)
				{			
					if (str[j] < str[j + 1])
					{	
					char swap = str[j];
					str[j] = str[j + 1];
					str[j + 1] = swap;
					}
				}
		}
	}
	
void selectionSort(char *str, int lenght)
{
	int i;	
	for (i = 0; i < lenght - 1; i ++)
	{
		int k = i;
		int j;	
		for (j = i + 1;j < lenght; j ++)
		{
			if (str[j]>str[k])
			{				
				k = j;
			}
		}
		
		char swap = str[i];
		str[i] = str[k];
		str[k] = swap;
	}
}

void insertionSort(char *str, int lenght)
{
	int i;
	for (i = 1; i < lenght; i ++)
	{
		char swap = str[i];
		int j = i;
		while (j > 0 && (str[j-1] >= swap))
		{
			str[j] = str[j - 1];
			-- j;
		}	
			str[j] = swap;
	}
}
