#include "dk_tool.h"

int strings(char string[], char search[])
{ //initiliazation our variables
	int i = 0;
	int j = 0;
	int k = 0;

	for (i = 0; string[i] != '\0'; i++)//in the loop we check if our array has something
	{
		for (j = i, k = 0; search[k] != '\0' && string[j] == search[k]; j++, k++);// check if our second array also has something; and if their symbols are matched, do iteration;
			//i - flag for entry point
		if (k > 0 && search[k] == '\0')// checking if we get the end of "search"
			return i+1;//return entry point
	}
	return -1;//if we don't get what we want returning -1;
}

