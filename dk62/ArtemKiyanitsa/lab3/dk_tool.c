#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dk_tool.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char *Transform_file (int *Lenght_of_Str)
{	

	FILE *file = fopen("string.txt","r");
	if(file == NULL)	
	{
		printf("File don't open string.txt\n");
		return 0;
	}
	int Lenght=0;
	while(fgetc(file)!=EOF)
	{		
		Lenght++;
	}
	
	printf("Lenght_of_File: %i\n",Lenght);
	
	char *String = (char *)malloc(sizeof(char)*(Lenght));
	
	fseek(file, 0L, SEEK_SET); 	
	int i = 0;
	int EOS;	//End Of String
	do
	{	
		EOS=fgetc(file);
		if(EOS!='\n')
		{
			String[i]=EOS;		
			i++;
		}	
	}while(EOS!=EOF);
	fclose(file);
	*Lenght_of_Str = i-1;
	return String;	
}

void shellSort(int Lenght_of_Str ,char *string)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= Lenght_of_Str/3)
	{
		theH = theH*3 + 1; 
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < Lenght_of_Str; theOuter ++)
		{
			int theTmp = string[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && string[theInner - theH] >= theTmp)
			{
				string[theInner] = string[theInner - theH];
				theInner -= theH;
			}
		
			string[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
}


unsigned line_find(int Lenght_of_Str ,char *string, char Key)
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

