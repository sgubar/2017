#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

clock_t sortShell(int array[], int n);

clock_t find(int array[], int n, int x, int *index);

void readNum(char *path, int **array, int *n);

void writeNum(char *path, int *array, int n);

#endif 