#include "Element.h"
#include <stdlib.h>
#include <string.h>

DoubleElement *CreateElementWithDoubleLink(char *aValue)
{
DoubleElement *theResult = (DoubleElement *)malloc(sizeof(DoubleElement));	
	theResult->str = (char *)malloc(sizeof(char)*(strlen(aValue)+1));
	strcpy(theResult->str,aValue);
	theResult->value = strlen(theResult->str);
	theResult->previousElement = NULL;
	theResult->nextElement = NULL;
	return theResult;
}

void FreeDoubleElement(DoubleElement *theElement)
{
	if (NULL != theElement)
	{
		if(NULL != theElement->str)
			free(theElement->str);
		free(theElement);
	}
}
