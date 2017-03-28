
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
#define space3 fprintf(aFile, "            ")
#define space2 fprintf(aFile, "        ")
#define space fprintf(aFile, "    ")
#define enter fprintf(aFile, "\n")
#define comma fprintf(aFile, ",")

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

void writeList(FILE * aFile ,SpherePosition *aSphere)
{
	
	
	fprintf (aFile, "{");
	enter;
	space3;
	fprintf (aFile, "\"X\": %i", aSphere->xPosition);
	comma;
	enter;
	space3;
	fprintf (aFile, "\"Y\": %i", aSphere->yPosition);
	comma;
	enter;
	space3;
	fprintf (aFile, "\"Z\": %i", aSphere->zPosition);
	comma;
	enter;
	space3;
	fprintf (aFile, "\"Radius\": %i", aSphere->radius);
	enter;
	space2;
	fprintf (aFile, "}");
	
    
}


void writeInFile(FILE *aFile, SphereList *aSphere)
{
	int i;
	fprintf (aFile, "{");
	enter;
	space;
	fprintf(aFile, "\"size\" : %d", aSphere->size);
	comma;
	enter;
	space;
	fprintf(aFile, "\"current size\" : %d", aSphere->current_size);
	comma;
	enter;
	space;
	fprintf(aFile, "\"Notes\" : ");
	if (NULL == aSphere->spheres)
	{
		fprintf(aFile, "Null");
	}
	else
	{
		fprintf(aFile, "[");
		enter;
		space2;
	
		for (i = 0; i < aSphere->current_size; i++)
		{
			SpherePosition *theList = &(aSphere->spheres[i]);
		
			writeList(aFile, theList);
		
			if (i < (aSphere->current_size - 1))
			{
				comma;
				enter;
				space2;
			}
		}
	    enter;
	    space;
		fprintf(aFile, "]");
	}
	enter;
	fprintf (aFile, "}");
}

void writeOnScreen(SpherePosition *aSphere)
{
	if(NULL == aSphere)
	{
		printf("Null");
	}
	else
	{

	printf ("{");
	printf ("\n");
	printf ("\"X\": \"%i\"", aSphere->xPosition);
	printf ("\n");
	printf ("\"Y\": \"%i\"", aSphere->yPosition);
	printf ("\n");
	printf ("\"Z\": \"%i\"", aSphere->zPosition);
	printf ("\n");
	printf ("\"Radius\": \"%i\"", aSphere->radius);
	printf ("\n");
	printf ("}");
    }
}

void writeListOnScreen(SphereList *aSphere)
{
	int i;
	for (i = 0; i < aSphere->current_size; i++)
		{
			SpherePosition *theList = &(aSphere->spheres[i]);
		
			writeOnScreen(theList);
		
			if (i < (aSphere->current_size - 1))
			{
				printf(",");
				printf("\n");
				printf(" ");
			}
		}
	    printf("\n");
	    printf(" ");
		printf("]");
	
	printf ("\n");
	printf ("}\n");
	
}

