#include <stdio.h>
#include <string.h>
#include "dk_tool.h"

int search(char *str, char *txt)
{
	int result = 0, i = 0, j = 0;			
	while(i < strlen(str))					
	{
		if(str[i] == txt[j])				
		{
			do{								
				i++;
				j++;
				if(j == strlen(txt) - 1)
				{
					result++;
				}
			}while(str[i] == txt[j] && str[i] != '\0');	
			
			j = 0;							
		}
		else
		{
			i++;
		}
	}
return result;							
}
