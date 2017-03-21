#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#include <stdlib.h>

#define pi 3.14

typedef struct 
{
	int x;
	int y;
	int rad;
} circle;

double square(circle c);

char init(circle **array, int *n, int x, int y, int rad);

#endif