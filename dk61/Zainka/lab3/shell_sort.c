#include <stdio.h>
#include "shell_sort.h"
#include "dk_tool.h"
#include <string.h>


char *shell_sort( int aSize, char *neotsortmassiv )
{
	    int i, hod = aSize / 2;
	while (hod > 0)
    {
      for (i = 0; i < (aSize - hod); i++)
        {
      	  int j = i;
          while (j >= 0 && neotsortmassiv[j] < neotsortmassiv[j + hod] )                        
            {
        		swap(&neotsortmassiv[j], &neotsortmassiv[j+hod]);
                j--; 
            }
		}
    hod /= 2; 
	} 
return neotsortmassiv;
}


void swap (char *var1, char *var2)
{
	char temp = *var1;
	*var1 = *var2;
    *var2 = temp;
}
