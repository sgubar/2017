#include "Element.h"
#include <stdlib.h>
#include <string.h>

DoubleElement *CreateElementWithDoubleLink(int aValue)
{
	DoubleElement *theResult = (DoubleElement *)malloc(sizeof(DoubleElement));
	theResult->value = aValue;
	theResult->previousElement = NULL;
	theResult->nextElement = NULL;
	
	return theResult;
}

void FreeDoubleElement(DoubleElement *theElement)
{
	if (NULL != theElement)
	{
		free(theElement);
	}
}
