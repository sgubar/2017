//
//  ordArray.c
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "ordArray.h"
#include <stdlib.h>
#include <strings.h>

ordArrayPtr oa_create(unsigned aSize)
{
	ordArrayPtr theArray = (ordArrayPtr)malloc(sizeof(ordArray));
	if (NULL != theArray)
	{
		theArray->size = 0;
		theArray->maxSize = aSize;
		theArray->storage = (int *)malloc(sizeof(int) * aSize);
	
		bzero(theArray->storage, aSize);
	}
	
	return theArray;
}

void oa_destroy(ordArrayPtr anArray)
{
	if (NULL != anArray)
	{
		if (NULL != anArray->storage)
		{
			free(anArray->storage);
		}
	
		free(anArray);
	}
}

unsigned oa_insert(ordArrayPtr anArray, int aValue)
{
	unsigned theResult = anArray->size;
	
	int i = 0;
	
	if (anArray->size == anArray->maxSize)
	{
		return theResult;
	}
	
	for (; i < anArray->size; i ++)
	{
		if (anArray->storage[i] > aValue)
		{
			theResult = i;
			break;
		}
	}
	
	for (int j = anArray->size; j > i; j --)
	{
		anArray->storage[j] = anArray->storage[j - 1];
	}
	
	anArray->storage[i] = aValue;
	anArray->size ++;
	
	return theResult;
}

unsigned oa_delete(ordArrayPtr anArray, int aValue)
{
	unsigned theResult = oa_find(anArray, aValue);
	
	if (theResult == anArray->size)
	{
		return theResult;
	}
	
	for (int j = theResult; j < anArray->size; j ++)
	{
		anArray->storage[j] = anArray->storage[j + 1];
	}
	
	anArray->size --;
	
	return theResult;
}

unsigned size(ordArrayPtr anArray)
{
	return anArray->size;
}

unsigned oa_find(ordArrayPtr anArray, int aValue)
{
	unsigned theResult = anArray->size;
	unsigned theLowerBound = 0;
	unsigned theUpperBound = anArray->size - 1;
	unsigned theCurIn = 0;
	
	while (1)
	{
		theCurIn = (theLowerBound + theUpperBound) / 2;
		if (anArray->storage[theCurIn] == aValue) //<!- an element was found
		{
			theResult = theCurIn;
			break;
		}
		else if (theLowerBound > theUpperBound) //<!- all elements were viewed
		{
			break;
		}
		else
		{
			if (anArray->storage[theCurIn] < aValue)
			{
				theLowerBound = theCurIn + 1; //!<- in upper position
			}
			else
			{
				theUpperBound = theCurIn - 1; //!<- in lower position
			}
		}
	
	}
	
	return theResult;
}

void oa_print(ordArrayPtr anArray)
{
	printf ("\n{");
	
	for (int i = 0; i < anArray->size; i ++)
	{
		printf ("%d", anArray->storage[i]);
		if (i < anArray->size - 1)
		{
			printf (",");
		}
	}
	
	printf ("}\n");
}
