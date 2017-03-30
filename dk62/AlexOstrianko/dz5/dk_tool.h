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

typedef struct tagGaraj
{
	Car *kolvo;
	int max;
	int curent;
}Garaj;

int BinarySearch(Garaj *PGar, char *aName);
void swap(Garaj *PGar, int aLeftIndex, int aRightIndex);
char *mediana(Garaj *PGar, int aLeftIndex, int aRightIndex);
int m_partitionIt(Garaj *PGar, int aLeftIndex, int aRightIndex, char *aPivot);
void quickSort2(Garaj *PGar, int aLeftIndex, int aRightIndex);
void m_manualSort(Garaj *PGar, int aLeftIndex, int aRightIndex);
Garaj *CreateGaraj(int Size);
void AddCar (Garaj *PGar,char *InpName);
void DelCar(Car *PCar);
#endif
