#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hw4.h"


SphereList * createSphereList(int aSize)
{
	SphereList *newList = (SphereList *)malloc(sizeof(SphereList)); //distinguish  memories to create a list
	
	if(newList != NULL)
	{
		newList->spheres = (SpherePosition *)malloc(aSize * sizeof(SpherePosition));
		memset(newList->spheres, 0 , aSize * sizeof(SpherePosition));
		
		newList->size = aSize;
		newList->currentSize = 0;		
	}
	return newList;
}

int createnewSphere(SphereList *aSphere, int x,int y, int z, int R) //the function transfer list and set the parameters Sphere
{
	if(NULL != aSphere && 0 < R) //check is there the list and radius  more 0
	{
		if(aSphere -> currentSize < aSphere->size)
		{
			SpherePosition *theSphere = &(aSphere->spheres[aSphere->currentSize]);
			if( NULL != theSphere) 
			{
				theSphere -> x = x; //fill the array
				theSphere -> y = y;
				theSphere -> z = z;
				theSphere -> R = R;
				
				aSphere->currentSize ++;
			}
		}
		else
		return 0;
	}
	else
	{
	    return 0;
    }
    return 0;
}


float Squareareas(SpherePosition * Sphere)
{
	return  4 * 3.14 * pow(Sphere->R,2);	
}

void removeSphereList(SphereList *aSphere)
{
	if(NULL != aSphere)
	{
		if(NULL != aSphere-> spheres)
		{
			free(aSphere-> spheres);
		}
		free(aSphere);
	}
}

void shellSort(SphereList *aSphere)
{
	int i = 0;
	int j = 0;
	int H = 1; 
	
	while (H <= aSphere->currentSize/3)
	{
		H = H*3 + 1; 
	}

	while (H > 0)
	{
		for (j = H; j < aSphere->currentSize; j ++)
		{
			SpherePosition Tmp = aSphere->spheres[j];
			i = j;
			while (i > H-1 && Squareareas(&aSphere->spheres[i - H]) >= Squareareas(&Tmp))
			{
				aSphere->spheres[i] = aSphere->spheres[i - H];
				i -= H;
			}
		
			aSphere->spheres[i] = Tmp;
		}
	
		H = (H - 1) / 3;
	}	
}

int binarySearch(SphereList *aSphere, int find)
{
	int left = 0;
	int right = aSphere->currentSize - 1;
	int middle;

    while(left <= right)
    {
    	int middle = (right + left) / 2;
         if(aSphere->spheres[middle].R == find)
        {
            return middle;
        }
        else if(aSphere->spheres[middle].R >find)
        {
        	right = middle - 1;
    	}
    	else 
    	{
    		left = middle+1;
		}
    }
    return -1;
}









