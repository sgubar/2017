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
		if(EOS!='\n'){
			String[i]=EOS;		
			i++;
		}	
	}while(EOS!=EOF);
	fclose(file);
	*Lenght_of_Str = i-1;
	return String;	
}

void selectionSort(int Lenght_of_Str ,char *string)
{
	int theOut;	
	for (theOut = 0; theOut < Lenght_of_Str - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;	
		for (theIn = theOut + 1;theIn < Lenght_of_Str; theIn ++)
		{
			if (string[theIn]<string[theMinIndex])
			{				
				theMinIndex = theIn;
			}
		}
		
		char theTmp = string[theOut];
		string[theOut] = string[theMinIndex];
		string[theMinIndex] = theTmp;
//			printf ("%c\n",string[theOut]);
	}

}

void bubbleSort(int Lenght_of_Str ,char *string)
{
	int theOut;
	for (theOut = Lenght_of_Str-1; theOut > 0; theOut --)
	{
		int theIn;
		for (theIn = 0; theIn < theOut; theIn ++)
		{
			if (string[theIn] > string[theIn + 1])
			{
				char theTmp = string[theIn];
				string[theIn] = string[theIn + 1];
				string[theIn + 1] = theTmp;
			}
		}
	}
}

void insertionSort(int Lenght_of_Str ,char *string)
{
	int theOut;
	for (theOut = 1; theOut < Lenght_of_Str; theOut ++)
	{
		char theTmp = string[theOut];
		int theIn = theOut;
		while (theIn > 0 && (string[theIn-1] >= theTmp))
		{
			string[theIn] = string[theIn - 1];
			-- theIn;
		}	
			string[theIn] = theTmp;
	}
}
