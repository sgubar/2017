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