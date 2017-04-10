#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#include <stdlib.h>
#include <stdio.h>

#define pi 3.14

typedef struct 
{
	int x;
	int y;
	int rad;
} circle;

double square(circle c);

char init(circle **array, int *n, int x, int y, int rad);

char output(char *path, circle *array, int n);

void sortBubble(circle **array, int n);

void sortInsert(circle **array, int n);

void sortSelect(circle **array, int n);

#endif