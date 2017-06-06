#include <stdio.h>
#include <string.h>
#include "tool.h"


int main()
{
    char str[255];
    char *ptr=str;
    printf("Vvedite stroku: ");
    gets(str);
    int result=findWord(ptr);
	printf ("V stroke slov: %d ", result );    
    return 0;
}
