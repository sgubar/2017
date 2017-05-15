#include "dk_tool.h"

double square(circle c)  
{
	return c.rad*c.rad*pi;
}


char init(circle **array, int *n, int x1, int y1, int rad1) 
{
	if (rad1 < 0)
		return 1;
	if (*array == NULL) 
	{
		*array = (circle*)malloc(sizeof(circle));
		*n = 1;
		if (*array == NULL)
			return 1;
		(**array).x = x1;
		(**array).y = y1;
		(**array).rad = rad1;
	} 
	else 
		{
			*array = (circle*)realloc(*array,(*n + 1)*sizeof(circle));
			if (*array == NULL)
				return 1;
			(*array)[*n].x = x1;
			(*array)[*n].y = y1;
			(*array)[(*n)++].rad = rad1;

		}
	return 0;
}

char output(char *path, circle *array, int n) 
{
	if (path == NULL)
		return 1;
	FILE *file = fopen(path, "w");
	if (file == NULL)
		return 1;
	fprintf(file,"{\n\t\"Array\": [\n");
	for (int i = 0; i < n; i++) 
	{
		fprintf(file,"\t\t\{\n\t\t\t\"X\": %i,\n\t\t\t\"Y\": %i,\n\t\t\t\"Radius\": %i,\n\t\t\t\"Square\": %.2f\n\t\t}",\
			array[i].x,array[i].y,array[i].rad,square(array[i]));
		if (i != n - 1)
			fprintf(file, ",");
		fprintf(file, "\n");
		
	}
	fprintf(file,"\t]\n}\n");
	fclose(file);
	return 0;
}

void sortShell(circle array[], int n) 
{

	int theInner = 0;
	int theOuter = 0;
	int theH = 1; 

	while (theH <= n/3)
	{
		theH = theH*3 + 1; 
	}
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < n; theOuter ++)
		{
			circle theTmp = array[theOuter];
			theInner = theOuter;

			while (theInner > theH-1 && array[theInner - theH].rad < theTmp.rad)
			{
				array[theInner] = array[theInner - theH];
				theInner -= theH;
			}

			array[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; 
	}
}

int find(circle array[], int n, int x) 
{
	for (int i = 0; i < n; i++)
		if (array[i].rad == x) 
		{
			return i;
		}
	return -1;
}