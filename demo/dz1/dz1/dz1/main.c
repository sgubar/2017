//
//  main.c
//  dz1
//
//  Created by Slava Gubar on 2/14/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "dk_tool.h"

int main(int argc, const char * argv[])
{
	char theString[] = "test_help";
	int theLength = test_getLength(theString);
	
	printf("[MAIN]. The length of the string <%s> is <%d>\n", theString, theLength);
	
	return 0;
}
