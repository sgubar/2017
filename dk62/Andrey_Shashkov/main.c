#include <stdio.h>
#include <ctype.h>
#include "dk_tool.h"

int main(int argc, const char * argv[])
{
	char masslength[100];
	
    printf ("Write the text:\n");

    char *string = gets (masslength);
    
	int thewords = test_getwords(string);
	
	printf ("nomber of words:%d\n " , thewords);
	
	return 0;
}
