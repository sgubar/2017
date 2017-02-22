#include "dk_tool.h"

#include "dk_tool.h"

int test_getwords(char *string)

{
	int lon = 0;
	
	int Getlength = 0;
	
	while(string[lon] != '\0')
   {
        if(string[lon + 1] ==' ')
        {
            if(isalpha(string[lon]))
            {
                Getlength++;
            }
        }
        else
        {
        	if(string[lon + 1] =='\0')
        	{
        		if(isalpha(string[lon]))
                {
                    Getlength++;
                }
			}
		}
        lon++; 
   }
	
	return Getlength;
}
