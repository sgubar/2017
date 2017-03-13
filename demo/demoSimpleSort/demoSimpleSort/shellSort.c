//
//  shellSort.c
//  demoSimpleSort
//
//  Created by Slava Gubar on 4/19/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include "shellSort.h"

void shellSort(int anArray[], int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= aCount/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter ++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && anArray[theInner - theH] >= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}
		
			anArray[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
}