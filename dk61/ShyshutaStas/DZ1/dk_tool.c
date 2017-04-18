#include "dk_tool.h"

#include "dk_tool.h"

int test_getwords(char *string)

{
	int length = 0;
	
	int Getwords = 0;
	
	while(string[length] != '\0')
   {
        if(string[length + 1] ==' ')
        {
            if(isalpha(string[length]))
            {
                Getwords++;
            }
        }
        else
        {
        	if(string[length + 1] =='\0')
        	{
        		if(isalpha(string[length]))
                {
                    Getwords++;
                }
			}
		}
        length++; 
   }
	
	return Getwords;
}
