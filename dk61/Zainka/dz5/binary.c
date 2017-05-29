#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include "dk_tool.h"


int binary_search(float key, filepiramida *polochka)
{
     int left = 0, right = polochka->current_size - 1, middle;
    	 printf("%i",  key );
    while (1)
    {
    	middle = left + (right - left) / 2;
     if (area( &polochka->Piramida[middle] ) == key) 
	 	return 0; //find
     if ( left >= right  ) 
	 	break;
	 else 
	 if (area( &polochka->Piramida[middle] ) < key)
     		{
     			 right = middle - 1;			//num in the right half
			}
           
        else
            {
     			left = middle + 1;			//num in the left half
			}
    }
    return -1;
}
