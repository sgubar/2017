#include <stdio.h>
#include <string.h>
#include "tool.h"

int findWord (char *str)
{
	int a=0;
	int i;
  for (i = 0;i < strlen(str)-1; i++)
{
    if((str[i] == ' ')&&(str[i+1] != ' '))
	{ 
	  a++;	
	}
}
 if (str[0] != ' ')
	  {
	  a++;
	  }
return a;
}
       

