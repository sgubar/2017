#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include "lw.h"
int main (void) 
{ 
float time, time1, time2; 
char method; 
char *aline; 

FILE *file = fopen("txt.txt", "r"); 
char line[1000]; 
if (file == NULL) 
{ 
printf("Sorry, but file not found.\n"); 
return -1; 
} 
aline = fgets(line, sizeof(line), file); 
printf("Elements of the file: %s \n", line); 
int counter = strlen(line); 

printf ("\nClosing file: "); 
if ( fclose (file) == EOF) printf ("Error\n"); 
else printf ("Complete.\n"); 
printf("\n");


printf("Sorting method of choice:\n");
clock_t time0=clock();
sorting_Choice( line, counter); 
printf("Your sorted array: \n"); 
for(int i = 0; i < counter; i++) 
{ 
printf("%c ", line[i]); 
} 
time = clock()-time; 
printf("\n"); 
printf("The time of sorting: %.3f sec\n ", time / CLOCKS_PER_SEC); 
printf("\n"); 


printf("Sort by bubbles:\n");
time1=clock();
sorting_Bubble( line, counter); 
printf("Your sorted array: \n"); 
for(int i = 0; i < counter; i++) 
{ 
printf("%c ", line[i]); 
} 
time1 = clock()-time1; 
printf("\n"); 
printf("The time of sorting: %.3f sec \n", time1 / CLOCKS_PER_SEC); 
printf("\n"); 


printf("Sort by inserting:\n");
time2=clock();
sorting_Inserts( line, counter); 
printf("Your sorted array: \n"); 
for(int i = 0; i < counter; i++) 
{ 
printf("%c ", line[i]); 
} 
time2 = clock()-time2; 
printf("\n"); 
printf("The time of sorting: %.3f sec ",  time2/ CLOCKS_PER_SEC); 

}
