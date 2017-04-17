
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define aSize 500
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	FILE *aFile = fopen("random.txt","w");
	FILE *sortedFile = fopen("SortedFile.txt","w");
	char *charArray[aSize];
	char *sortingArray[aSize];
	
	printf("Enter some text: ");
	gets(charArray);
	
	printRandomToFile(aFile,charArray);
	//readFromFile(charArray,sortingArray);
     
	printf("Please,select a type of sort: 1.Selection,    2.Insertion,    3.Bubble.\n");
	
	int a;
	do
	{
	    int theTmp = scanf("%d",&a);         
	    if(theTmp == 1)                            
	    {
		    break;
	    }
	    printf("Please,try again: ");
	    fflush(stdin);
    }
	while(1);
	
    int i = 0;
    float StartTime = clock();
	switch(a)
	{
		case 1:
				
	        readFromFile(charArray,sortingArray);
	        puts(sortingArray);
			//float selectionStart = clock();
			selectionSort(sortingArray);
		    float selectionEnd = clock() - StartTime;
			//float selectionResult = (selectionEnd - selectionStart)/CLOCKS_PER_SEC;
			printf("The time of Selection sorting is:%.0f\n",selectionEnd);
			printToFile(sortedFile,sortingArray);
			break;
				
		case 2:
				
			readFromFile(charArray,sortingArray);
			
			//clock_t insertionStart = clock();
			insertionSort(sortingArray);
			float insertionEnd = clock() - StartTime;
			//float insertionResult = (insertionEnd - insertionStart)/CLOCKS_PER_SEC;
			printf("The time of Insertion sorting is:%.0f\n",insertionEnd);
			printToFile(sortedFile,sortingArray);
			break;	
				
		case 3:
		        
		    readFromFile(charArray,sortingArray);
				
			//clock_t bubbleStart = clock();
			bubbleSort(sortingArray);
			float bubbleEnd = clock() - StartTime;
			//float bubbleResult = (bubbleEnd - bubbleStart)/CLOCKS_PER_SEC;
	        printf("The time of Bubble sorting is:%.0f\n",bubbleEnd);
	        printToFile(sortedFile,sortingArray);
	        break;
	    }
	    
	return 0;
}


