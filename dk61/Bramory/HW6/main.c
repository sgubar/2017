#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include "List.h"
#include "sort.h"



int main( void )
{
	srand(time(0));
	IntList *theList = CreateIntList();
	if (NULL == theList)
	{
		return -1;
	}
	
	int z = 0;
	float timeForAdd = clock();
	int count = pow(10, 1);
	for(z = 0; z < count;  z++)
	{
		AddIntValueToList(theList, random(9999) );
	}
	timeForAdd = clock()  - timeForAdd;
	
	int buffer = 100;
	char var;
	char *type = (char *) malloc(sizeof(char) * buffer);
	memset(type, 0, sizeof(char) * buffer);
	type ="Original";
	
	char *path  = (char *) malloc(sizeof(char) * buffer);
	memset(path, 0, sizeof(char) * buffer); 
	getcwd(path, buffer);
	strcat(path, "\\TL_NodeList\\"); // directory for the results
	mkdir(path);
	
	fileWrite(type, count, theList);
	
	count <= 10 ? PrintList(theList)
				: printf("\nSee full array in the file\n");
	
	printf ("The value at index %d: %d\n", -1, IntValueAtIndex(theList, -1));
	printf ("The value at index %d: %d\n", 0, IntValueAtIndex(theList, 0));
	printf ("The value at index %d: %d\n", 1, IntValueAtIndex(theList, 1));
	printf ("The value at index %d: %d\n", 5, IntValueAtIndex(theList, 5));
	printf ("The value at index %d: %d\n", 7, IntValueAtIndex(theList, 7));
	
	printf ("The count of value in the list: %d\n\n", theList->count);
	printf ("After adding 5 at Index '0' \n");
	InsertIntValueAtIndex(theList, 5, 0);
	PrintList(theList);
	
	printf ("\nSelect the type of the sort");
	printf ("\n(s)hell, (q)uick \n");
	
	var = getch();
	float timeForSort = clock();
	switch(var)
	{
		case 'q': type = "Quick"; QuickSort_NodeList(theList, 0, theList->count - 1); break; 
		case 's': type = "Shell"; Shell_Sort_NodeList(theList); break; 
		default : type = "None";  break; 
	}
	timeForSort = clock() - timeForSort;
	printf ("\nAfter %s Sort: \n", type);
	
	count <= 10 ? PrintList(theList)
			: printf("\nSee full array in the file\n");

	printf("TimeForAdd = %.3f msec\n", timeForAdd);
	printf("TimeForSort = %.3f msec\n", timeForSort);


	memset(path, 0, sizeof(char) * buffer); 
	getcwd(path, 100);
	strcat(path, "\\TL_NodeList\\"); // directory for the results
	fileWrite(type, count, theList);
	
	DestroyIntList(theList);
	
//	free(type);			????	
	free (path);
	return 0;
}

