#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"


SphereList * createSphereList(int aSize)
{
	SphereList *theList = (SphereList *)malloc(sizeof(SphereList));
	
	if(theList != NULL)
	{
		theList->spheres = (SpherePosition *)malloc(aSize * sizeof(SpherePosition));
		memset(theList->spheres, 0 , aSize * sizeof(SpherePosition));
		
		theList->size = aSize;
		theList->current_size = 0;		
	}
	return theList;
}


void destroySphereList(SphereList *aSphere)
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


int addSphere(SphereList *aSphere, int x,int y, int z, int radius)
{
	if(NULL != aSphere && 0 < radius)
	{
		if(aSphere -> current_size < aSphere->size)
		{
			SpherePosition *theSphere = &(aSphere->spheres[aSphere->current_size]);
			if( NULL != theSphere)
			{
				theSphere -> xPosition = x;
				theSphere -> yPosition = y;
				theSphere -> zPosition = z;
				theSphere -> radius = radius;
				
				aSphere->current_size ++;
			}
		}
		else
		return -3;
	}
	else
	{
	    return -2;
    }
    return 0;
}


float areaCalculation(SpherePosition * theSphere)
{
	return  4 * 3.14 * theSphere->radius * theSphere->radius;	
}


int enterParametersOfSphere(void)
{
	int a;
	printf("Enter x, y, z - coordinate and radius: ");   
	do
	{
	    int theTmp = scanf("%d",&a);         
	    if(theTmp == 1)                            
	    {
		    break;
	    }
	    printf("Please,try again: ");
	    fflush(stdin);
    }
	while(1);
	
    return a;                               
}

