
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dk_tool.h"
#include <time.h>



int main (void)
{
	int SIZE = 100;
	

	FILE *txt_file = fopen("Text.txt" , "r");//відкриваю читаймий фал
	
		if(txt_file == NULL)//перевірка на існування
    	{
      	 printf("The following file not found/n");//якщо файл не існує вивести
       	 return -1; 
   		}
   	
   		printf ("file open\n");//якщо файл існує 
   	 char *charArray = (char*) malloc(sizeof(char)*SIZE );
   	 
   	 
   	int i= 0 ;//номер яч
    int c ;
   	do
   	{
   		c=fgetc(txt_file);
   		if (isalpha(c)||isdigit(c))//перевірка на те чи є с буквою 
   		{
			charArray[i] = c ;
   			i++;
		}
	
	}
	while ( !feof(txt_file));//доки не кінць файла 
	
	fclose (txt_file);
	
	  int j;
    for(j=0 ; j < strlen(charArray); j++)   
   {
   		printf("%c ", charArray[j]);
   }
    	printf("\n size of array = %d\n", strlen(charArray));
 
 
 
 char *sortingArray=(char*) malloc(sizeof(char)*strlen(charArray) );
 
 sortingArray = shell_sort( strlen(charArray),charArray );

 
 FILE *sortedFile = fopen("SortedFile.txt","w");//створюємо папку для відсортованого масиву
   	
	   
	   if( sortedFile== NULL)//перевірка на існування
    	{
      	 printf("The following file not found/n");//якщо файл не існує вивести
       	 return -1; 
   		}
   	
   		printf ("file open\n");//якщо файл існує 	
   		
 i=0;
 int  length = strlen(sortingArray);
   for(i=0 ; i<length; i++)   
   {
   	fprintf(sortedFile, "%c",sortingArray[i]);
   	
   }
   		printf("\n conets");
   		fclose(sortedFile);
   		
   		

   	return 0;
}

