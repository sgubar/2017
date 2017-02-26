#include <stdio.h>
#include <string.h>
#include "dk_tool.h"

int sea(char str[], char search[])
 {
	int result = 0, i = 0, j = 0;
	while(i < strlen(str))
    	{
		if(str[i]==search[j])
		  {
			do{
				i++;
				j++;
				if(j == strlen(search)-1)
					result++;
			  }while(str[i]==search[j]&&str[i]!='\0');
	     	j = 0;
		}
    
    	else
    	i++;
	  } 
	return result;
}
