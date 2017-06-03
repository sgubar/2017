#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <time.h>
#include "dk_tool.h"
#include "shell_sort.h"

int binary_search(char key, int aSize, char *Sortmassiv)
{
    
    
	int left = 0, right = aSize, middle;

    while (left <= right )
    {
    	middle =   (left+right)/2;
     if (Sortmassiv[middle] == key)
	  return middle; 
     else 
	 if (Sortmassiv[middle] < key)
            right = middle-1;		
        else
            left = middle+1;			

}
   return -1;
           

}

