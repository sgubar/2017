#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>



#include "dk_tool.h"

char *Transform_file_text_to_str (int *InpInt){	
	FILE *file = fopen("some_file.txt","r");
	if(file == NULL)	
	{
		printf("File don't open some_file.txt");
		return 0;
	}
	int Lenth_of_File=0;
	while(fgetc(file)!=EOF)
	{		
		Lenth_of_File++;
	}
	printf("Lenth_of_File: %i\n",Lenth_of_File);
	
	char *String = (char *)malloc(sizeof(char)*(Lenth_of_File+1));
	
	fseek(file, 0L, SEEK_SET); 	
	int i = 0;
	char Proverka_na_n;	
	do
	{	
		Proverka_na_n=fgetc(file);
		if(Proverka_na_n!='\n'){
			String[i]=Proverka_na_n;
			//printf("%c",Proverka_na_n);		
			i++;
		}	
	}while(Proverka_na_n!=EOF);
	*InpInt = i;
	fclose(file);
	return String;	
}

void Vivod (int Lenth, char *PStr){
	int i =0;
	printf("\n");
	while(i<Lenth)
	{
		printf("%c",PStr[i]);
		i++;
	}
}

void selectionSort(int lenth ,char *string)
{
	int theOut;	
	for (theOut = 0; theOut < lenth - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;	
		for (theIn = theOut + 1;theIn < lenth; theIn ++)
		{
			if (string[theIn]<string[theMinIndex])
			{				
				theMinIndex = theIn;
			}
		}
	
		char theTmp = string[theOut];
		string[theOut] = string[theMinIndex];
		string[theMinIndex] = theTmp;
	}
}

void bubbleSort(int lenth, char *string)
{
	int theOut;
	for (theOut = lenth-1; theOut > 0; theOut --)
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

void insertionSort(int lenth, char *string)
{
	int theOut;
	for (theOut = 1; theOut < lenth; theOut ++)
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
