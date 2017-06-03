#include <stdio.h>
#include "sort.h"
#include "dk_tool.h"
#include <string.h>
char *bubble_sort( int Size, char *neotsortmassiv )
{
	int i, j, result;
	for (i = 1; i < Size; i++)
	{
		result = 0; 						//	flag: sorted
		for (j = 1; j < Size-i+1; j++)   
		{
	        if (neotsortmassiv[j] < neotsortmassiv[j-1])
	        {
				swap(&neotsortmassiv[j], &neotsortmassiv[j-1]);
	        	result ++; 					//	flag: not sorted
	        }
		}	
		if(!result) break;
	}
return neotsortmassiv;
}

void swap (char *var1, char *var2)
{
	char temp = *var1;
	*var1 = *var2;
    *var2 = temp;
}


char *selection_sort( int Size, char *neotsortmassiv )
{
	int i,j, max, temp;
	    for (i = 0; i < Size; i++)   // ïðîõ ïî ìàññèâó
    {
        max = i;  // ïðèñâ  1 çíà÷ ìàêñ 
        for (j = i+1; j < Size; j++)
            if (neotsortmassiv[j] > neotsortmassiv[max]) //ïîð³â ñ ìàêñ 
                max = j; // èçìåíÿåì

            if ( max != i)      //if it's not sorted
				swap(&neotsortmassiv[i], &neotsortmassiv[max]); // ñâàï
    }
return neotsortmassiv;
}




char *insertion_sort(int Size , char *neotsortmassiv)
{
	int theOut;
	for ( theOut = 1; theOut < Size; theOut ++) //ïðîõîä ïî ìàññèâó 
	{
		int theTmp = neotsortmassiv[theOut]; // çàïèñü â òåïì  , îáðàùàåìñÿ ê îóò
		int theIn = theOut; // 1 ïðèñâàåâàåì 
	
		while (theIn > 0 && neotsortmassiv[theIn - 1] <= theTmp)   
		{
			neotsortmassiv[theIn] = neotsortmassiv[theIn - 1];
			-- theIn;
		}
	
		neotsortmassiv[theIn] = theTmp;
	}
return neotsortmassiv;
}
