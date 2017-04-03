#include <stdio.h>
#include "sort.h"
#include "tool.h"

void selection_sort( int aSize, int *srcArray )
{
	int i,j, max, temp;
	    for (i = 0; i < aSize; i++)   
    {
        max = i;
        for (j = i+1; j < aSize; j++)
            if (srcArray[j] < srcArray[max])
                max = j;

            if ( max != i)      //if it's not sorted
				swap(&srcArray[i], &srcArray[max]);
    }
}

void bubble_sort( int aSize, int *srcArray )
{
	int i, j, result;
	for (i = 1; i < aSize; i++)
	{
		result = 0; 						//	flag: sorted
		for (j = 1; j < aSize-i+1; j++)   
		{
	        if (srcArray[j] < srcArray[j-1])
	        {
				swap(&srcArray[j], &srcArray[j-1]);
	        	result ++; 					//	flag: not sorted
	        }
		}	
		if(!result) break;
	}
}


void insertion_sort(int aSize, int *srcArray )
{
	int theOut;
	for ( theOut = 1; theOut < aSize; theOut ++)
	{
		int theTmp = srcArray[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && srcArray[theIn - 1] >= theTmp)
		{
			srcArray[theIn] = srcArray[theIn - 1];
			-- theIn;
		}
	
		srcArray[theIn] = theTmp;
	}
}


void shell_sort( int aSize, int *srcArray )
{
	    int i, step = aSize / 2;
	while (step > 0)
    {
      for (i = 0; i < (aSize - step); i++)
        {
      	  int j = i;
          while (j >= 0 && srcArray[j] > srcArray[j + step] )                        
            {
        		swap(&srcArray[j], &srcArray[j+step]);
                j--; 
            }
		}
    step /= 2; 
	} 
}

void quick_sort(int A[], int b0, int e0)
{
	int key = A[e0];
	int b = b0;
	int e = e0;
	
	do
	{
		while(A[b] < key)
			++b;
		while(A[e] > key)
			--e;
		if ( b <= e )
		{
			swap (&A[b], &A[e]);
			b++;
			e--;
		}
	}
	while(b <= e); 
	
	if (e > b0)
		quick_sort(A, b0, e); //left
	if (b < e0)
		quick_sort(A, b, e0); //right
}


