#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

typedef struct matrica
{
	int dlinna;
	int visota;
	int mass[10][10];
	int dlinna_transp;
	int visota_transp;
	int transponovanaya_mass[10][10];
} matrixa;

void print(struct matrica *inM);
void matrix (struct matrica *inM);
void transp (struct matrica *inM);

#endif
