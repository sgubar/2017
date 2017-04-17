#include <stdio.h>
#include "dk_tool.h"
#include <string.h>
#include <stdlib.h>
void printRandomToFile(FILE *aFile, char *charArray)
{
	
	if (aFile == NULL) 
	{
	printf("Can not open file.\n");
    }
	
	fputs(charArray,aFile);

	fclose(aFile);

}

void readFromFile( char*charArray,char * sortingArray)
{
	FILE *theFile = fopen("random.txt","r");
	if(theFile == NULL)
	{
		printf("Your file is not found!\n");
		return -1;
	}
	else
	fgets(sortingArray,strlen(charArray),theFile);
	fclose(theFile);
		
}

void printToFile(FILE *aFile , char* sortedArray)
{
	
	if(sortedArray == NULL)
	{
		return -2;
	}
	fputs(sortedArray,aFile);
	fclose(aFile);
}
