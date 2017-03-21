#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include "dk_tool.h"

int main(void){	
	
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
	
	char String[Lenth_of_File+1];
	
	fseek(file, 0L, SEEK_SET); 	
	int i = 0;
	char Proverka_na_n;	
	do
	{	
		Proverka_na_n=fgetc(file);
		if(Proverka_na_n!='\n'){
			String[i]=Proverka_na_n;
			printf("%c",Proverka_na_n);		
			i++;
		}	
	}while(Proverka_na_n!=EOF);
	Lenth_of_File = i+1;
	
//	selectionSort(Lenth_of_File,String);
//	bubbleSort(Lenth_of_File,String);
	insertionSort(Lenth_of_File,String);
	
	Vivod(Lenth_of_File,String);

	fclose(file);

	return 0;
}
