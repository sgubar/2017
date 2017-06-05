
#include <stdio.h>
#include "dk_tool.h"



void ShellSort(char *str, int lenght)
{
	int i = 0;
	int j = 0;
	int bobbi = 1; 
	
	while (bobbi <= lenght/3)
	{
		bobbi = bobbi*3 + 1; 
	}

	
	while (bobbi > 0)
	{
		for (j = bobbi; j < lenght; j ++)
		{
			int swap = str[j];
			i = j;
		
		
			while (i > bobbi-1 && str[i - bobbi] <= swap) 
			{
				str[i] = str[i - bobbi];
				i -= bobbi;
			}
		
			str[i] = swap;
		}
	
		bobbi = (bobbi - 1) / 3;
	}
}

int LineSearch(FILE *file2, char marker, char *str, int lenght)
{
	int counter;
	printf("FIND (enter): ");
	scanf("%c", &marker);
	
	
	for (int i = 0; i < lenght; i++)
	{
		if (str[i] == marker)
		{
		counter++;
		}
	}
	
	if (counter > 0)
	{
		printf("The [%c] symbol occurs %i times\n", marker, counter);
		fprintf(file2, "The [%c] symbol occurs %i times\n", marker, counter);	
	}
	else
	{
		printf("There is no such symbol in the file\n");
		fprintf(file2," There is no such symbol in the file\n");
	}
}
