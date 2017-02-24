#ifndef DK_TOOL_H
#define DK_TOOL_H

#include <stdio.h>
#include <stdlib.h>

int **matr;

void init(const int n, const int m);

void fill(const int n, const int m);

void product(const int n, const int m, const int p);

void delete(const int n, const int m);

void show(const int n, const int m);

#endif
