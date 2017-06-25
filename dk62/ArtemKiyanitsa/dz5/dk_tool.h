#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagKol
{
	char pokr[10];
	char disk[10];
}Koleso;

typedef struct tagCar
{
	char *Name;
	Koleso *kolvo;
	int max;
	int curent;
}Car;

typedef struct tagPark
{
	Car *kolvo;
	int max;
	int curent;
}Park;

int BinarySearch(Park *PointerPark, char *aName);
void swap(Park *PointerPark, int aLeftIndex, int aRightIndex);
char *mediana(Park *PointerPark, int aLeftIndex, int aRightIndex);
int m_partitionIt(Park *PointerPark, int aLeftIndex, int aRightIndex, char *aPivot);
void quickSort2(Park *PointerPark, int aLeftIndex, int aRightIndex);
void m_manualSort(Park *PointerPark, int aLeftIndex, int aRightIndex);
Park *CreatePark(int Size);
void AddCar (Park *PointerPark,char *InpName);
void DeleteCar (Car *PointerCar);
#endif
