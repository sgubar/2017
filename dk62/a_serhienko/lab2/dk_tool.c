#include "dk_tool.h"
#include<string.h>
#include <stdio.h>


void PrintToFile(FILE *unsortedfile, char *unsortedarray)
{
	// Checking on opening file
	if (unsortedfile == NULL) printf("error\n");
	else printf("done\n");

	//writining in file
	
	fputs(unsortedarray,unsortedfile);

	printf("writing has been complete\n");

	// closing file
	fclose(unsortedfile);
	printf("file is closed\n");

	


}

void ReadingFromFile(FILE*unsortedfile, char *unsortedarray, char*arrayforsorting)
{
	printf("opening file : ");
	fopen_s(&unsortedfile, "unsorted.txt", "r");

	// cheking if file is open
	if (unsortedfile == NULL) { printf("error\n"); }
	else printf("done\n");

	
	
	fgets(arrayforsorting,strlen(unsortedarray)+1,unsortedfile);
		

	
	

	//Closing file
	printf("\nClosing the file \n");
	if (fclose(unsortedfile) == EOF) printf("error \n");
	else printf("done\n");

}




void PrintSortedArraytoFile(FILE *sortedfile, char *arrayforsorting) 
{

	if (sortedfile == NULL) printf("error\n");
	else printf("done\n");

	//for (int i = 0; i<=strlen(arrayforsorting); i++)
	
	fputs(arrayforsorting,sortedfile);

	printf("writing has been complete\n");

	// closing file
	fclose(sortedfile);
	printf("file is closed\n");
}

