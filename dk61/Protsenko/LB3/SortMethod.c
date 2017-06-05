#include "SortMethod.h"

void bubbleSort(char *str, int string_lenght)
	{
		for (int theOut = string_lenght-1; theOut > 0; theOut --)
		{		
			int theIn;
				for (int theIn = 0; theIn < theOut; theIn ++)
				{			
					if (str[theIn] > str[theIn + 1]) //change < to >
					{	
					char theTmp = str[theIn];
					str[theIn] = str[theIn + 1];
					str[theIn + 1] = theTmp;
					}
				}
		}
	}
	
void selectionSort(char *str, int string_lenght)
{
	int theOut;	
	for (theOut = 0; theOut < string_lenght - 1; theOut ++)
	{
		int theMinIndex = theOut;
		int theIn;	
		for (theIn = theOut + 1;theIn < string_lenght; theIn ++) 
		{
			if (str[theIn]<str[theMinIndex]) //change > to < 
			{				
				theMinIndex = theIn;
			}
		}
		
		char theTmp = str[theOut];
		str[theOut] = str[theMinIndex];
		str[theMinIndex] = theTmp;
	}
}

int FileOpenCheck(FILE*file, FILE*file2)
{
		if (fopen == NULL)  //check did the file open
		{
		 printf("Error...\n");
		 return 0;
		}
}

int FileCloseCheck(FILE *file2, FILE *file) //check, is a file2 closed or not
{
	//printf ("\nClosing SortedValues: ");//
   		if (fclose (file2) == EOF)
		   { 
		    printf ("Error. 'SortedValues.txt' is not closed.\n");
		   }
   	   else
		   {
		    printf ("");
		   }
		   
	//printf ("Closing ValueContainer: ");//
	
	
   		if (fclose (file) == EOF)
		   {
		    printf ("Error. 'ValueContainer.txt' is not closed.\n");
		   }
   	   else
		   {
		    printf ("");
           }	
}

void MoveArrayPoint(FILE *file)
{
	if (fseek (file,0,SEEK_SET)==0) //check, has a point moved or isn't
      	 printf (" ");
    else
         printf ("Error\n");
}

void ShellSort(char *str, int string_lenght)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1
	
	//1. Calculate start value of h
	while (theH <= string_lenght/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < string_lenght; theOuter ++)
		{
			int theTmp = str[theOuter];
			theInner = theOuter;
		
			// the first sub-array {0, 4, 8}
			while (theInner > theH-1 && str[theInner - theH] >= theTmp)   //change >= to <=
			{
				str[theInner] = str[theInner - theH];
				theInner -= theH;
			}
		
			str[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3; //decrease h
	}
}

int LineSearch(FILE *file2, char key, char *str, int string_lenght)
{
	printf("\nEnter symbol to find : ");
	scanf("%c", &key);
	printf("\n -Line Search-\nYou entered : %c\n", key );
	fprintf(file2, "\n -Line Search-\nYou entered : %c\n", key);
	int symbol_count;
	
	for (int i = 0; i < string_lenght; i++)
	{
		if (str[i] == key)
		{
		printf("[%i] ", i);
		fprintf(file2, "[%i] ", i);
		symbol_count++;
		}
	}
	
	if (symbol_count > 0)
	{
		printf("- Symbols position. Totally found %i symbols\n", symbol_count);
		fprintf(file2, "- Symbols position. Totally found %i symbols\n", symbol_count);	
	}
	else
	{
		printf("  !!!Not found!!!  \n");
		fprintf(file2,"  !!!Not found!!!  \n");
	}
}
