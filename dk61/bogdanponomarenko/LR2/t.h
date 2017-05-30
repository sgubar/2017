#ifndef t_h
#define t_h

#include <stdio.h>

int *createArray(int Asize);

int fillingArray(int *AnArray, int Asize);

void WriteToFile(FILE *file, int *AnArray, int Asize, float Time);

float Sort(int *AnArray, int Asize);

int scan(int min, int max);

//void Show(int *AnArray, int Asize, float Time);



#endif 


