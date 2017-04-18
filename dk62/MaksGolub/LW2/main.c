#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"


int main(void)
{   
	FILE *aFile = fopen("data1.txt","r");
    int length = LengthFile(aFile); //length of file;
	
	char *MasFile = StrFile(aFile, length); //create mass of symbol for selection sorting;
	selectionSort(length, MasFile);
        
	char *MasFile1 = StrFile(aFile, length); //create mass of symbol for bubble sorting;
	bubbleSort(length, MasFile1);
	
	char *MasFile2 = StrFile(aFile, length); //create mass of symbol for insertion sorting;
    insertionSort(length, MasFile2);
    
    
    PrintFile(length, MasFile2); //print result sorting in file;
	
	free(MasFile); 
	free(MasFile1);
	free(MasFile2);
	fclose(aFile);
	
    return 0;
}
