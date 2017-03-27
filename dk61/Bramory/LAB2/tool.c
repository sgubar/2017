#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

int read_filename( char* inputFile, int aSize)
{
	memset(inputFile, '\0', aSize * sizeof(char));
	int In = 0;
	char sym = 'a';
	while( 1 ) 
	{
			if (In >= aSize)
		{
			free(inputFile);
			return -5;
		}	
		sym = getchar();
		printf("%c", sym);
		if (sym != 10)
		inputFile[In] = sym;
		else break;
		In++;
	}
//strcpy(inputFile, "test.txt");
	return 0;
}

char random_char (char min, char max)
{
    return rand() % (max-min+1) + min;
}

void print_array(int size, char srcArray[size])
{
	int i;
	for (i = 0; srcArray[i] != '\0'; i++)   
		printf("%c", srcArray[i] );
    
	printf("\n");
}

void fillArrayChar(char min, char max, int size, char srcArray[size])
{
	memset(srcArray, '\0', sizeof(char) * size );
	int i;
	  for (i = 0; i < size; i++)
      srcArray[i] = random_char(min, max);
}

char *scan_text(int *aSize, char *filename)
{
	FILE *aFile = fopen (filename, "r");
	if (NULL != aFile)
	{
		int i = 0, c;
		char *ptrArray = (char *) malloc(sizeof(char) * *aSize);
		memset (ptrArray, '\0', sizeof(char) * *aSize);
		while (1)
		{
			if (*aSize <= i) //overflow
			{
				*aSize = -1;
				break;
			}
			if (c == EOF) break; //end of file
			c = fgetc(aFile);
			if ( isalpha(c) )
			{
				ptrArray[i] = c;
				i++;
			}
		}
		fflush(aFile);
		fclose (aFile);
		return ptrArray;
	}

}

int fileWrite(char *name_of_sort, int size, char srcArray[size])
{
	int i;
	char *filename = (char *)malloc (sizeof(char) * 200);
	char *path = (char *)malloc (sizeof(char) * 100);
	getcwd(path, 100);
	strcpy(filename, path );
	strcat(filename, "\\Sorted_Arrays\\");
	strcat(filename, name_of_sort);
	strcat(filename, ".txt");
	FILE *aFile = fopen(filename, "w");
	if (NULL != aFile)
	{
		for(i = 0; srcArray[i] != '\0'; i ++ )
		fprintf (aFile, "%c",  srcArray[i]);
			
		free(filename);	
		free(path);	
		fflush(aFile);
		fclose(aFile);
		return 0;
	}
	else 
	{
		free(filename);	
		free(path);
		printf("Couldn't create output file..\n");
		return -1;
	}
}

