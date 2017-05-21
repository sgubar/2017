
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw3.h"

SphereList *createSphereList(int aSize)
{
	SphereList *newList = (SphereList *) malloc(sizeof(SphereList));
	
	if(newList != NULL)
	{
		newList->spheres = (SpherePosition *) malloc(aSize * sizeof(SpherePosition));
		memset(newList->spheres, 0, aSize * sizeof(SpherePosition));
		
		newList->size = aSize;
		newList->currentSize = 0;
	}
	return newList;
}

int createnewSphere(SphereList *aSphere, int x, int y, int z, int R)
{
	if(NULL != aSphere && R > 0)
	{
		if(aSphere->currentSize < aSphere->size)
		{
			SpherePosition *theSphere = &(aSphere->spheres[aSphere->currentSize]);
			if( NULL != theSphere) 
			{
				theSphere -> x = x;
				theSphere -> y = y;
				theSphere -> z = z;
				theSphere -> R = R;
				
				aSphere->currentSize ++;
			}
		}
		else
			return 21;
	}
	else
	{
	    return 34;
    }
    return 0;
}

float Squareareas(SpherePosition *Sphere)
{
	return  4 * 3.14 * pow(Sphere->R, 2);	
}

void removeSphereList(SphereList *aSphere)
{
	if(NULL != aSphere)
	{
		if(NULL != aSphere->spheres)
			free(aSphere->spheres);
			
		free(aSphere);
	}
}

void printSphere(SphereList *Sphere)
{
	if(Sphere->currentSize != 0)
	{
		int i;
		FILE *file = fopen("File.json", "w");
		
		fprintf(file, "{\"Size\":%i,", Sphere->size);
		fprintf(file, "\"Current size\":%i", Sphere->currentSize);
		fprintf(file, ",\"Spheres\":[\n");
		
		printf("Size: %i, Current size: %i\n", Sphere->size, Sphere->currentSize);
		printf("Spheres:\n");
		
		for(i = 0; i < Sphere->currentSize; i++)
		{
			SpherePosition *firstSphere = &(Sphere->spheres[i]);
			printf("Figure #%i, X: %i, Y: %i, ", i, firstSphere->x, firstSphere->y);
			printf("Z: %i, Radius: %i, ", firstSphere->z, firstSphere->R);
			printf("Square of sphere: %.3f\n", Squareareas(firstSphere));
			fprintf(file, "{\n");
			fprintf(file, "\t\"X\":%i,\n", firstSphere->x);
			fprintf(file, "\t\"Y\":%i,\n", firstSphere->y);
			fprintf(file, "\t\"Z\":%i,\n", firstSphere->z);
			fprintf(file, "\t\"R\":%i\n", firstSphere->R);
			fprintf(file, "}\n");
			firstSphere = NULL;
		}
		fprintf(file, "]");
		fprintf(file, "}\n");
		
		fflush(file);
		fclose(file);
	}
}
