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

void sorting_Inserts(SphereList *aSphere)
{
	int i;
	
	for (i = 1; i < aSphere->currentSize; i ++)
	{
		SpherePosition Tmp = aSphere->spheres[i];
		int j = i;
	
		while (j > 0 && aSphere->spheres[j - 1].R >= Tmp.R)
		{
			aSphere->spheres[j] = aSphere->spheres[j - 1];
			-- j;
		}
	
		aSphere->spheres[j] = Tmp;
	}
}
void bubble_Sort(SphereList *aSphere)
{
	int i;
	int j;
	for (i = aSphere->currentSize - 1; i > 1; i--)
	{
		for ( j = 0; j < i; j ++)
		{
			if (aSphere->spheres[j].R > aSphere->spheres[j + 1].R)
			{
				SpherePosition Tmp = aSphere->spheres[j];
				aSphere->spheres[j] = aSphere->spheres[j + 1];
				aSphere->spheres[j + 1] = Tmp;
			}
		}
	}
}

void selection_Sort(SphereList *aSphere)
{
	int i;
	int j;
	for (i = 0; i < aSphere->currentSize - 1; i ++)
	{
		int MinIndex = i;
	
		for (j = i + 1; j < aSphere->currentSize; j ++)
		{
			if (aSphere->spheres[j].R < aSphere->spheres[MinIndex].R)
			{
				MinIndex = j;
			}
		}
	
		SpherePosition Tmp = aSphere->spheres[i];
		aSphere->spheres[i] = aSphere->spheres[MinIndex];
		aSphere->spheres[MinIndex] = Tmp;
	}
}
/*int switchh(int m)
	
switch(m)
        {
            case 1:
            bubbleSort(Sphere);
            break;

            case 2:
            sorting_Inserts(Sphere);
            break;

            case 3:
           selectionSort(Sphere);
            break;
            return 0;
        } */


