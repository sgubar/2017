#include <stdio.h>
#include <string.h> 
#include "dk_tool.h"

int werb_number (char *string)
{
	int i;
    int werbs = 1;
    int length = strlen(string);
    for (i=0;i<length;i++)
    {
        if (string[i]== ' ')
        {
            werbs++;
        }
    }
    return werbs;
}
