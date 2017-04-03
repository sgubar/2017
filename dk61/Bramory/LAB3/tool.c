#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tool.h"

int binary_search(int key, int aSize, int *srcArray)
{
    int left = 0, right = aSize-1, middle;
//    	printf("%i",  key );
    while (left <= right )
    {
    	middle = (left+right)/2;
     if (srcArray[middle] == key) return 0; //find
     else if (srcArray[middle] > key)
            right = middle-1;			//num in the right half
        else
            left = middle+1;			//num in the left half
    }
    return -1;
}

int line_search(int key, int aSize, int *srcArray)
{
	int i;
	printf("\nkey = %i\n",  key );
	for (i = 0; i < aSize; i++)
	{
		if (srcArray[i] == key) return 0;
	}	
	
	return -1;
}

void printArray(int A[], int aSize )
{
	int i;
	printf("{");	
	for(i = 0; i < aSize; i++)
	{
		printf("%d", A[i]);
		if(i < aSize-1)
		printf(", ");
	}
	printf("}");
	printf("\n");
}

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
	return 0;
}

int random_int (int min, int max)
{
    return rand() % (max-min+1) + min;
}

//								 amount of elements
void fillArrayInt(int min, int max, int aSize, int *srcArray)
{
	int i;
	for (i = 0; i < aSize; i++)
    	srcArray[i] = random_int(min, max);
}

int *read_num(int *aSize_of_buff, char *filename)
{
	FILE *aFile = fopen (filename, "r");
	if (NULL != aFile)
	{
		int i = 0, c = 1;
		int aSize = *aSize_of_buff;
		int *ptrArray = (int *) malloc(sizeof(int) * aSize + 1);
		memset (ptrArray, 0, sizeof(int) * aSize);
		while (1)
		{
			if (aSize <= i) //overflow
			{
				free(ptrArray);
				*aSize_of_buff = -1;
				break;
			}
			int prepare = 0, flag = 1;
			while ( isdigit(c = fgetc(aFile)) )
			{
				if (prepare != 0) 
				prepare *= 10;
				prepare += c - 48; //ASCII for '0'
				flag = 0;
			}
			if (flag == 0)
			{
				ptrArray[i] = prepare;
				i++;	
			}
			if (c == EOF) break; //end of file
		}
		
		
		*aSize_of_buff = i;	// real size of array from file
		fflush(aFile);
		fclose (aFile);
		return ptrArray;
	}
}

int fileWrite(char *name_of_sort, int aSize, int *srcArray)
{
	int i;
	char *path_of_file = (char *)malloc (sizeof(char) * 200);
	memset(path_of_file, 0, sizeof(char) * 200);
	getcwd(path_of_file, 100);
	strcat(path_of_file, "\\Sorted_Arrays\\"); //new dir
	strcat(path_of_file, name_of_sort);
	strcat(path_of_file, ".txt");
	FILE *aFile = fopen(path_of_file, "w");
	if (NULL != aFile)
	{
		for(i = 0; i < aSize; i ++ )
		fprintf (aFile, "%i ",  srcArray[i]);
			
		free(path_of_file);	
		fflush(aFile);
		fclose(aFile);
		return 0;
	}
	else 
	{
		free(path_of_file);
		printf("Couldn't create output file..\n");
		return -1;
	}
}

void swap (int *var1, int *var2)
{
	int temp = *var1;
	*var1 = *var2;
    *var2 = temp;
}

int num_scan( void )
{
	int value;
		while(1)
		{
			int proof = scanf("%i", &value);
			if (proof == 1) 
				break;
			else 
				printf("Enter a number, please\n");
			fflush(stdin);
		}
	return value;
}
