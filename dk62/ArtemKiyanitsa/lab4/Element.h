#ifndef Element_h
#define Element_h

#include <stdio.h>

typedef struct __DoubleElement DoubleElement;

struct __DoubleElement
{
	char *str;
	int value;
	DoubleElement *previousElement;
	DoubleElement *nextElement;
};

DoubleElement *CreateElementWithDoubleLink(char *aValue);
void FreeDoubleElement(DoubleElement *theElement);

#endif
