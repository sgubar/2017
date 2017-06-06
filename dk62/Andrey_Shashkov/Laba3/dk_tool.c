#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"


char *Transform_file (int *Lenght_of_Str)
{	

	FILE *file = fopen("file.txt","r");
	if(file == NULL)	
	{
		printf("File don't open string.txt\n");
		return 0;
	}
	int Lenght=0;
	while(fgetc(file)!=EOF)
	
	int Length = ftell(file);
	
	printf("Lenght_of_File: %i\n",Lenght);
	
	char *String = (char *)malloc(sizeof(char)*(Lenght));
	
	fseek(file, 0L, SEEK_SET); 	
	int i = 0;
	int element;	
	do
	{	
		element=fgetc(file);
		if(element!='\n')
		{
			String[i]=element;		
			i++;
		}	
	}while(element!=EOF);
	fclose(file);
	*Lenght_of_Str = i-1;
	return String;	
}




void shellSort(int Lenght_of_Str ,char *string)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1;
	
	while (theH <= Lenght_of_Str/3)
	{
		theH = theH*3 + 1; 
	}

	while (theH > 0)
	{
		for (theOuter = theH; theOuter < Lenght_of_Str; theOuter ++)
		{
			int theTmp = string[theOuter];
			theInner = theOuter;
		
			while (theInner > theH-1 && string[theInner - theH] >= theTmp)
			{
				string[theInner] = string[theInner - theH];
				theInner -= theH;
			}
		
			string[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; 
	}
}


unsigned lineSearch(int Lenght_of_Str ,char *string, char Key)
{
	unsigned theResult;
	int i;
	for ( i = 0; i < Lenght_of_Str; i++)
	{
		if (string[i] == Key)
		{
			theResult = i;
			break;
		}
	}
	
	return theResult;
}
