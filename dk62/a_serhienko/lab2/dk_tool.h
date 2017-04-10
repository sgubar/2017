#ifndef dk_tool		
#define dk_tool	
#include <stdio.h>


void PrintToFile(FILE *unsortedfile, char *unsortedarray);
void ReadingFromFile(FILE*unsortedfile,char *unsortedarray, char *arrayforsorting);

void PrintSortedArraytoFile(FILE *sortedfile, char *arrayforsorting);


#endif /*dk_tool*/
