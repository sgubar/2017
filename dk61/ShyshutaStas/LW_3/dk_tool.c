#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"



char *shell_sort( int SIZE, char *charArray )
{
	    int i, step = SIZE / 2;
	while (step > 0)
    {
      for (i = 0; i < (SIZE - step); i++)
        {
      	  int j = i;
          while (j >= 0 && charArray[j] < charArray[j + step] )                        
            {
        		swap(&charArray[j], &charArray[j+step]);
                j--; 
            }
		}
    step/= 2; 
	} 
	return charArray;
}

void swap (char *var1, char *var2)
{
	char temp = *var1;
	*var1 = *var2;
    *var2 = temp;
}

