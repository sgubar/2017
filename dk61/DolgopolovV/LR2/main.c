#include "dk_tool.h"
#define MAX 1000

int main(void)
{	
	FILE *fileR = fopen("Read.txt", "r"); 
	FILE *fileW = fopen("Write.txt", "w");  

	if (fopen == NULL)  
	{
		printf("Error\n");
		return 0;
	}
char ch=0;	
char str[MAX];	   
fgets(str, MAX, fileR); 
int string_lenght = strlen(str); 
	
printf("Before sorting: %s\n", &str);
fprintf(fileW, "Before sorting: %s\n", &str);
fclose(fileR);
	
	
while(1)
{
printf("Select one of the options:\n\n");
printf("1. Bubble Sort.\n");
printf("2. Selection Sort.\n");
printf("3. Insertion Sort.\n");
printf("Enter the number of the selected item:");
ch = getchar();
unsigned int StartTime =  clock();
if (ch == '1' || ch == '2' || ch == '3' )
break;
}
switch (ch)
{
case '1': 
	bubbleSort(str, string_lenght); 

case '2':        
	selectionSort(str, string_lenght);

case '3':
	selectionSort(str, string_lenght); 
}
	unsigned int EndTime = clock();
	unsigned int SearchTime = EndTime - StartTime;

	printf("\nAfter sorting: %s\n", &str); 
	fprintf(fileW, "\nAfter sorting %s\n", &str);
	printf("BubbleSort_Time: %.10f\n\n",(double)(SearchTime/CLOCKS_PER_SEC)); 
	fprintf(fileW,"BubbleSort_Time: %.10f\n",(double)(SearchTime/CLOCKS_PER_SEC));
	fclose(fileW);
}
