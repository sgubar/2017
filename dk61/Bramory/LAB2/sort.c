#include <stdio.h>
#include "sort.h"
#include "tool.h"

int binary_search(char key, int size, char srcArray[size])
{
    int left = 0, right = size-1, middle;
    	printf("%c",  key );
    while (left <= right )
    {
    	middle = (left+right)/2;
     if (srcArray[middle] == key) return 1; //find
     else if (srcArray[middle] > key)
            right = middle-1;			//num in the right half
        else
            left = middle+1;			//num in the left half
    }
    return 0;
}

int line_search(char key, int size, char srcArray[size])
{
	int i;
	printf("\nkey = %c\n",  key );
	for (i = 0; i < size-1; i++)
	{
		if (srcArray[i] == key) return 1;
	}	
	
	return 0;
}

void selection_sort( int size, char *srcArray )
{
	int i,j, max, temp;
	    for (i = 0; i < size; i++)   
    {
        max = i;
        for (j = i+1; j < size; j++)
            if (srcArray[j] > srcArray[max])
                max = j;

            if ( max != i)      //if it's not sorted
				swap(&srcArray[i], &srcArray[max]);
    }
}

void bubble_sort( int size, char *srcArray )
{
	int i, j, result;
	for (i = 1; i < size; i++)
	{
		result = 0; 						//	flag: sorted
		for (j = 1; j < size-i+1; j++)   
		{
	        if (srcArray[j] > srcArray[j-1])
	        {
				swap(&srcArray[j], &srcArray[j-1]);
	        	result ++; 					//	flag: not sorted
	        }
		}	
		if(!result) break;
	}
}


void insertion_sort(char anArray[], int aSize)
{
	int theOut;
	for ( theOut = 1; theOut < aSize; theOut ++)
	{
		int theTmp = anArray[theOut];
		int theIn = theOut;
	
		while (theIn > 0 && anArray[theIn - 1] <= theTmp)
		{
			anArray[theIn] = anArray[theIn - 1];
			-- theIn;
		}
	
		anArray[theIn] = theTmp;
	}
}


void shell_sort( int size, char *srcArray )
{
	    int i, step = size / 2;
	while (step > 0)
    {
      for (i = 0; i < (size - step); i++)
        {
      	  int j = i;
          while (j >= 0 && srcArray[j] < srcArray[j + step] )                        
            {
        		swap(&srcArray[j], &srcArray[j+step]);
                j--; 
            }
		}
    step /= 2; 
	} 
}

/*
void quick_sort( int size, char *srcArray )
{
	int i,j, max, temp;
	    for (i = 0; i < size; i++)   
    {
            //if it's not sorted
			//	swap(&srcArray[i], &srcArray[max]);
    }
}

void merge_sort(int low, int high, char *srcArray, char *temp) 
{
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      merge_sort(low, mid, srcArray, temp);
      merge_sort(mid+1, high, srcArray, temp);
      merging(low, mid, high, srcArray, temp);
   } else { 
      return;
   }   
}

void merging(int low, int mid, int high, char *srcArray, char *temp) 
{
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(srcArray[l1] <= srcArray[l2])
         temp[i] = srcArray[l1++];
      else
         temp[i] = srcArray[l2++];
   }
   
   while(l1 <= mid)    
      temp[i++] = srcArray[l1++];

   while(l2 <= high)   
      temp[i++] = srcArray[l2++];

   for(i = low; i <= high; i++)
      srcArray[i] = temp[i];
}
*/ //for function in main: (0, size-1, myArray, temp)

void swap (char *var1, char *var2)
{
	char temp = *var1;
	*var1 = *var2;
    *var2 = temp;
}
