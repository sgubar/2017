#ifndef dk_tool_h
#include <stdio.h>
#define dk_tool_h


int GetValueWithCheck();
int GetValueWithSymbolCheck();
void CreateMatrix(int x, int y, int arr[x][y]);
void PrintMatrix(int x, int y, int arr[x][y]);
void SubstractMatrix(int x, int y, int arr[x][y], int arr2[x][y]);
#endif
