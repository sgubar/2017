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
			fprintf(file,",");
		fprintf(file,"\n");
		
	}
	fprintf(file,"\t]\n}\n");
	fclose(file);
	return 0;
}

// сортування бульбашкою
void sortBubble(circle **array, int n) 
{
	circle *a = *array;
	for (int r = n; r > 1; r--)
		for (int i = 0; i < r - 1; i++)
			if (a[i].rad < a[i+1].rad) 
			{
				circle b = a[i];
				a[i] = a[i+1];
				a[i+1] = b;
			}
}

// сортування вставкою
void sortInsert(circle **array, int n) 
{
	circle *a = *array;
	for (int i = 1; i < n; i++) 
	{
		circle b = a[i];
		int j = 0;
		while (b.rad < a[j].rad) 
			j++;
		for (int k = i - 1; k >= j; k--) 
			a[k+1] = a[k];
		a[j] = b;
	}
}

// сортування вибором
void sortSelect(circle **array, int n) 
{
	circle *a = *array;
	for (int s = 0; s < n - 1; s++) 
	{
		int imax = s;
		circle max = a[s];
		for (int i = s + 1; i < n; i++)
			if (a[i].rad > max.rad) 
			{
				max = a[i];
				imax = i;
			}
		a[imax] = a[s];
		a[s] = max;
	}
}