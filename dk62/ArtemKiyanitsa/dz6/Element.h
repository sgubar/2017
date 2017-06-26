#ifndef Element_h
#define Element_h

#include <stdio.h>

typedef struct __DoubleElement DoubleElement;

struct __DoubleElement
{
	double value;
	DoubleElement *previousElement;
	DoubleElement *nextElement;
};

DoubleElement *CreateElementWithDoubleValue(double aValue);
void FreeDoubleElement(DoubleElement *theElement);

#endif
