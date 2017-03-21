#include "dk_tool.h"

double square(circle c)  
{
	return c.rad*c.rad*pi;
}


char init(circle **array, int *n, int x, int y, int rad) 
{
	if (rad < 0)
		return 1;
	if (*array == NULL) 
	{
		*array = (circle*)malloc(sizeof(circle));
		*n = 1;
		if (*array == NULL)
			return 1;
		(**array).x = x;
		(**array).y = y;
		(**array).rad = rad;
	} 
	else 
	{
		*array = (circle*)realloc(*array,(*n + 1)*sizeof(circle));
		if (*array == NULL)
			return 1;
		(*array)[*n].x = x;
		(*array)[*n].y = y;
		(*array)[(*n)++].rad = rad;

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
	fprintf(file, "{\n");
	for (int i = 0; i < n; i++) 
	{
		fprintf(file,"\t\"Circle %i\": {\n\t\t\"X\": %i,\n\t\t\"Y\": %i,\n\t\t\"Radius\": %i,\n\t\t\"Square\": %.2f\n\t}",\
			i,array[i].x,array[i].y,array[i].rad,square(array[i]));
		if (i != n - 1)
			fprintf(file, ",");
		fprintf(file, "\n");
		
	}
	fprintf(file,"}\n");
	fclose(file);
	return 0;
}