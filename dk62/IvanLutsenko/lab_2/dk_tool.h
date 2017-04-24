#ifndef _DK_TOOL_H
#define _DK_TOOL_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

clock_t sortBubble(int **array, int n);

clock_t sortInsert(int **array, int n);

clock_t sortSelect(int **array, int n);

void readNum(char *path, int **array, int *n);

void writeNum(char *path, int *array, int n);

#endif 