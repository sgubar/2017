//
//  main.c
//  demoFind
//
//  Created by Slava Gubar on 5/10/16.
//  Copyright © 2016 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ordArray.h"

int main(int argc, const char * argv[])
{
	ordArrayPtr theArray = oa_create(200);
	
	srand(0);
	for (int i = 0; i < 180; i++)
	{
		oa_insert(theArray, rand() % 180);
	}

	oa_print(theArray);
	
	unsigned theIndex = oa_find(theArray, theArray->storage[10]);
	
	printf("\ntheIndex: %d\n", theIndex);
	
}
