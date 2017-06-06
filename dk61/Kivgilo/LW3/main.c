#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tool.h"
#include <locale.h>


int main(void)
{ 
	setlocale(LC_ALL, "Rus"); 	  
	FILE *aFile = fopen("data.txt","r");
    int length = LengthFile(aFile); //length of file;
	
	char *MasFile = StrFile(aFile, length); //create mass of symbol for selection sorting;
	//selectionSort(length, MasFile);
        
	char *MasFile1 = StrFile(aFile, length); //create mass of symbol for bubble sorting;
	//bubbleSort(length, MasFile1);
	
	char *MasFile2 = StrFile(aFile, length); //create mass of symbol for insertion sorting;
    //insertionSort(length, MasFile2);
    
    char *MasFile3 = StrFile(aFile, length);
    shellSort(length, MasFile3);
    
    char search;
    printf("Ââåäèòå ñèâîëû äëÿ  ïîèñêà:");
    scanf("%c", &search);
    int result = BinarySearch(length, MasFile3, search);
    printf("Ïîçèöèÿ èñêîìîãî ñèìâîëà:%d", result); 
    PrintFile(length, MasFile3); //print result sorting in file;
	
	free(MasFile); 
	free(MasFile1);
	free(MasFile2);
	free(MasFile3);
	fclose(aFile);
	
    return 0;
}
