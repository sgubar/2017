#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sorts.h"
#include "dk_tool.h"
#include "searches.h"
#include "cor_types.h"

void enter_values(int *Aarray_size, int *Atypetest, int *Atypevalues, int *Atypeval_similar, int *Atypeval_false, int *Atypesearch, int *Atypelin_arr, int *Avalue)
{
do{
    printf("Enter amount of elements (between 10 and 100000).\n");
	printf("Warning!!! If you choose 100000 elements and bubblesort, you'll lose performanse of your PC.\n\nEnter: ");
    *Aarray_size = gint();
}while(*Aarray_size < 10 || *Aarray_size > 100000);

do{
    printf("\nEnter number of type of sorting:\n0 - All types;\n1 - Bubble;\n2 - Merge;\n");
	printf("3 - Insertion;\n4 - Selection;\n5 - Shell;\n6 - Quick;\n\nEnter: ");
	*Atypetest = gint();
}while(*Atypetest < 0 || *Atypetest > 6);

do{
    printf("\nSelection of values:\n1. Several similar with choise of quantity;\n2. All random;\n");
	printf("3. Numbers in opposite order;\n4. Sorted array with one false number;\n\nEnter: ");
    *Atypevalues = gint();
}while(*Atypevalues < 1 || *Atypevalues > 4);

switch(*Atypevalues)
	{
	case 1:
		{
		do{
			printf("\nChoose quantity of similar numbers.");
			printf(" You can't enter value larger then %i amount of elements. Enter: ", *Aarray_size/5);
			*Atypeval_similar = gint();
		}while(*Atypeval_similar < 2 || *Atypeval_similar > *Aarray_size/5);
		break;
		}

	case 4:
		{
		do{
			printf("\nEnter number of location of false element:\n1 - First element;");
			printf("\n2 - Center element;\n3 - End of array;\n4 - Random place;\n\nEnter: ");
			*Atypeval_false = gint();
		}while(*Atypeval_false < 1 || *Atypeval_false > 4);
		break;
		}
	}

do{
    printf("\nEnter number of type of searching:\n0 - All types;\n1 - Line;\n");
	printf("2 - Binary;\n\nEnter: ");
	*Atypesearch = gint();
}while(*Atypesearch < 0 || *Atypesearch > 2);

if(*Atypesearch == 0 || *Atypesearch == 1)
	do{
		printf("\nEnter type of array for line search:\n0 - All types;\n1 - Sorted;\n");
		printf("2 - Unsorted;\n\nEnter: ");
		*Atypelin_arr = gint();
	}while(*Atypelin_arr < 0 || *Atypelin_arr > 2);

switch(*Atypevalues)
	{
	case 1:
		{
		do{
   			printf("Enter value to search (between 0 and %i).\n\nEnter: ", *Aarray_size/5);
   			*Avalue = gint();
   		}while(*Avalue < 0 || *Avalue > *Aarray_size/5);
		break;
		}
	case 2:
		{
		do{
   			printf("Enter value to search (between 0 and %i).\n\nEnter: ", 32767);
   			*Avalue = gint();
   		}while(*Avalue < 0 || *Avalue > 32767);
		break;
		}
	case 3:
		{
		do{
   			printf("Enter value to search (between 0 and %i).\n\nEnter: ", *Aarray_size);
   			*Avalue = gint();
   		}while(*Avalue < 0 || *Avalue > *Aarray_size);
		break;
		}
	case 4:
		{
		if(*Aarray_size > 32767)
			do{
   				printf("Enter value to search (between 0 and %i).\n\nEnter: ", *Aarray_size);
   				*Avalue = gint();
   			}while(*Avalue < 0 || *Avalue > *Aarray_size);
   		else
   			do{
   				printf("Enter value to search (between 0 and %i).\n\nEnter: ", 32767);
   				*Avalue = gint();
   			}while(*Avalue < 0 || *Avalue > 32767);
		break;
		}
	}
}

//-----------------------------------------------------------------------------------------------------------

void array_values_full_random(int *array, int array_size)
{
srand(time(NULL));
int i;
for(i = 0; i < array_size; i++)
	array[i] = rand();
}

//-----------------------------------------------------------------------------------------------------------

void array_values_typeval_similar(int *array, int array_size, int typeval_similar)
{
srand(time(NULL));
int i, tmp;
for(i = 0; i < array_size; i++)
	{
	tmp = rand() % typeval_similar;
	array[i] = tmp;
	}
}

//-----------------------------------------------------------------------------------------------------------

void array_values_opposite_order(int *array, int array_size)
{
int i;
for(i = 0; i < array_size; i++)
	array[i] = array_size - i - 1;
}

//-----------------------------------------------------------------------------------------------------------

void array_values_typeval_false(int *array, int array_size, int typeval_false)
{
srand(time(NULL));
int i;

switch(typeval_false)
	{
	case 1:
		{
		array[0] = rand();
		for(i = 1; i < array_size; i++)
			array[i] = i;
		break;
		}
	
	case 2:
		{
		int cen_ter = array_size/2;
		array[cen_ter] = rand();
		for(i = 0; i < array_size; i++)
			if(i != cen_ter)
				array[i] = i;
		break;
		}
	
	case 3:
		{
		int end = array_size - 1;
		array[end] = rand();
		for(i = 0; i < end; i++)
			array[i] = i;
		break;
		}
	
	case 4:
		{
		int abc = rand() % array_size;
		array[abc] = rand();
		for(i = 0; i < array_size; i++)
			if(i != abc)
				array[i] = i;
		break;
		}
	}
}

//-----------------------------------------------------------------------------------------------------------

void array_fill_values(int *array, int array_size, int typevalues, int typeval_similar, int typeval_false)
{
switch(typevalues)
	{
	case 1:
		{
		array_values_typeval_similar(array, array_size, typeval_similar);
		break;
		}
	case 2:
		{
		array_values_full_random(array, array_size);
		break;
		}
	case 3:
		{
		array_values_opposite_order(array, array_size);
		break;
		}
	case 4:
		{
		array_values_typeval_false(array, array_size, typeval_false);
		break;
		}
	}
}

//-----------------------------------------------------------------------------------------------------------

void array_sort(FILE *file, int *array, int *sec_array, int array_size, int typetest, int typevalues, int typeval_similar, int typeval_false)
{
clock_t time_start, time_end;
double time_sort;

char *sort = (char *) malloc(sizeof(char));
if(!sort)
	{
	printf("Memory Error!!!\n");
	free(sec_array);
	free(array);
	exit(10);
	}
char *fal = (char *) malloc(sizeof(char));
if(!fal)
	{
	printf("Memory Error!!!\n");
	free(sec_array);
	free(array);
	free(sort);
	exit(11);
	}

switch(typevalues)
	{
	case 1:
		{
		sort = (char *) realloc(sort, sizeof(char) * 40);
		if(!sort)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit(20);
			}
		strcpy(sort, "Several similar with choise of quantity");
		break;
		}
	case 2:
		{
		sort = (char *) realloc(sort, sizeof(char) * 11);
		if(!sort)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit(21);
			}
		strcpy(sort, "All random");
		break;
		}
	case 3:
		{
		sort = (char *) realloc(sort, sizeof(char) * 26);
		if(!sort)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit(22);
			}
		strcpy(sort, "Numbers in opposite order");
		break;
		}
	case 4:
		{
		sort = (char *) realloc(sort, sizeof(char) * 34);
		if(!sort)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit(23);
			}
		strcpy(sort, "Sorted array with one false value");
		break;
		}
	}

switch(typeval_false)
	{
	case 1:
		{
		fal = (char *) realloc(fal, sizeof(char) * 14);
		if(!fal)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit(30);
			}
		strcpy(fal, "First element");
		break;
		}
	case 2:
		{
		fal = (char *) realloc(fal, sizeof(char) * 15);
		if(!fal)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit (31);
			}	
		strcpy(fal, "Center element");
		break;
		}		
	case 3:
		{
		fal = (char *) realloc(fal, sizeof(char) * 13);
		if(!fal)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit(32);
			}
		strcpy(fal, "End of array");
		break;
		}
	case 4:
		{
		fal = (char *) realloc(fal, sizeof(char) * 13);
		if(!fal)
			{
			printf("Memory Error!!!\n");
			free(sort);
			free(fal);
			free(array);
			exit(33);
			}
		strcpy(fal, "Random place");
		break;
		}
	}


fprintf(file, "Type of sorting\t\tTime\t\t\t\t\t\t\tArray\t\tType of unsorted array");
if(typeval_false)
	fprintf(file, "\t\t\t\t\tPosition of false\n\n");
else
	fprintf(file, "\n\n");

switch(typetest)
	{
	case 0:
		{
		printf("\nPrepering...\n");
		}
	case 1:
		{
		printf("Bubble sort started...\n");
		time_start = clock();
		bubblesort(array, array_size);
		time_end = clock();
		time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
		printf("Bubble sort finished.\n");
		
		if(time_sort < 10000)
			fprintf(file, "Bubblesort\t\t\t%.18lf sec\t\t", time_sort);
		else
			fprintf(file, "Bubblesort\t\t\t%.18lf sec\t", time_sort);
			
		if(array_size < 1000)
			fprintf(file, "%i\t\t\t%s", array_size, sort);
		else
			fprintf(file, "%i\t\t%s", array_size, sort);
			
		if(typeval_false)
			fprintf(file, "\t\t%s\n", fal);
		else
			fprintf(file, "\n");
			
		if(typetest)
			break;
		else
			copy_values(array, sec_array, array_size);
		}
	case 2:
		{
		printf("Merge sort started...\n");
		time_start = clock();
		merge(array_size, array, 0, array_size - 1);
		time_end = clock();
		time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
		printf("Merge sort finished.\n");
		
		if(time_sort < 10000)
			fprintf(file, "Mergesort\t\t\t%.18lf sec\t\t", time_sort);
		else
			fprintf(file, "Mergesort\t\t\t%.18lf sec\t", time_sort);
			
		if(array_size < 1000)
			fprintf(file, "%i\t\t\t%s", array_size, sort);
		else
			fprintf(file, "%i\t\t%s", array_size, sort);
			
		if(typeval_false)
			fprintf(file, "\t\t%s\n", fal);
		else
			fprintf(file, "\n");
			
		if(typetest)
			break;
		else
			copy_values(array, sec_array, array_size);
		}
	case 3:
		{
		printf("Insertion sort started...\n");
		time_start = clock();
		insertionsort(array, array_size);
		time_end = clock();
		time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
		printf("Insertion sort finished.\n");
		
		if(time_sort < 10000)
			fprintf(file, "Insertionsort\t\t%.18lf sec\t\t", time_sort);
		else
			fprintf(file, "Insertionsort\t\t%.18lf sec\t", time_sort);
			
		if(array_size < 1000)
			fprintf(file, "%i\t\t\t%s", array_size, sort);
		else
			fprintf(file, "%i\t\t%s", array_size, sort);
			
		if(typeval_false)
			fprintf(file, "\t\t%s\n", fal);
		else
			fprintf(file, "\n");
			
		if(typetest)
			break;
		else
			copy_values(array, sec_array, array_size);
		}
	case 4:
		{
		printf("Selection sort started...\n");
		time_start = clock();
		selectionsort(array, array_size);
		time_end = clock();
		time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
		printf("Selection sort finished.\n");
		
		if(time_sort < 10000)
			fprintf(file, "Selectionsort\t\t%.18lf sec\t\t", time_sort);
		else
			fprintf(file, "Selectionsort\t\t%.18lf sec\t", time_sort);
			
		if(array_size < 1000)
			fprintf(file, "%i\t\t\t%s", array_size, sort);
		else
			fprintf(file, "%i\t\t%s", array_size, sort);
			
		if(typeval_false)
			fprintf(file, "\t\t%s\n", fal);
		else
			fprintf(file, "\n");
			
		if(typetest)
			break;
		else
			copy_values(array, sec_array, array_size);
		}
	case 5:
		{
		printf("Shell sort started...\n");
		time_start = clock();
		shellsort(array, array_size);
		time_end = clock();
		time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
		printf("Shell sort finished.\n");
		
		if(time_sort < 10000)
			fprintf(file, "Shellsort\t\t\t%.18lf sec\t\t", time_sort);
		else
			fprintf(file, "Shellsort\t\t\t%.18lf sec\t", time_sort);
			
		if(array_size < 1000)
			fprintf(file, "%i\t\t\t%s", array_size, sort);
		else
			fprintf(file, "%i\t\t%s", array_size, sort);
			
		if(typeval_false)
			fprintf(file, "\t\t%s\n", fal);
		else
			fprintf(file, "\n");
			
		if(typetest)
			break;
		else
			copy_values(array, sec_array, array_size);
		}
	case 6:
		{
		printf("Quick sort started...\n");
		time_start = clock();
		quicksort(array, 0, array_size - 1);
		time_end = clock();
		time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
		printf("Quick sort finished.\n");
		
		if(time_sort < 10000)
			fprintf(file, "Quicksort\t\t\t%.18lf sec\t\t", time_sort);
		else
			fprintf(file, "Quicksort\t\t\t%.18lf sec\t", time_sort);
			
		if(array_size < 1000)
			fprintf(file, "%i\t\t\t%s", array_size, sort);
		else
			fprintf(file, "%i\t\t%s", array_size, sort);
			
		if(typeval_false)
			fprintf(file, "\t\t%s\n", fal);
		else
			fprintf(file, "\n");
			
		if(typetest)
			break;
		}
	}

free(fal);
free(sort);
}

//-----------------------------------------------------------------------------------------------------------

void array_search(FILE *file, int *array, int *sec_array, int array_size, int typesearch, int typelin_arr, int value)
{
clock_t time_start, time_end;
double time_sort;

fprintf(file, "\nType of searching\tTime\t\t\t\t\t\t\tArray\t\tType of array\t\tValue\t\tResult\n\n");
int k;

switch(typesearch)
	{
	case 0:
		{
		printf("\nPrepering...\n");
		}
	case 1:
		{
		switch(typelin_arr)
			{
			case 0:
				{
				}
			case 1:
				{
				printf("Line search in sorted array started...\n");
				time_start = clock();
				k = line_search(value, array_size, array);
				time_end = clock();
				time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
				printf("Line search in sorted array finished.\n");
				
				if(time_sort < 10000)
					fprintf(file, "Line search\t\t\t%.18lf sec\t\t", time_sort);
				else
					fprintf(file, "Line search\t\t\t%.18lf sec\t", time_sort);
				
				if(array_size < 1000)
					fprintf(file, "%i\t\t\tSorted\t\t\t\t", array_size);
				else
					fprintf(file, "%i\t\tSorted\t\t\t\t", array_size);
				
				if(value < 1000)
					fprintf(file, "%i\t\t\t", value);
				else
					fprintf(file, "%i\t\t", value);
					
				if(k >= 0)
					fprintf(file, "%i\n", k);
				else
					fprintf(file, "Not founded!\n");
				
				if(typelin_arr)
					break;
				}
			case 2:
				{
				printf("Line search in unsorted array started...\n");
				time_start = clock();
				k = line_search(value, array_size, sec_array);
				time_end = clock();
				time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
				printf("Line search in unsorted array finished.\n");
				
				if(time_sort < 10000)
					fprintf(file, "Line search\t\t\t%.18lf sec\t\t", time_sort);
				else
					fprintf(file, "Line search\t\t\t%.18lf sec\t", time_sort);
				
				if(array_size < 1000)
					fprintf(file, "%i\t\t\tUnsorted\t\t\t", array_size);
				else
					fprintf(file, "%i\t\tUnsorted\t\t\t", array_size);
				
				if(value < 1000)
					fprintf(file, "%i\t\t\t", value);
				else
					fprintf(file, "%i\t\t", value);
				
				if(k >= 0)
					fprintf(file, "%i\n", k);
				else
					fprintf(file, "Not founded!\n");
				
				if(typelin_arr)
					break;
				}
			}
		if(typesearch)
			break;
		}
	case 2:
		{
		printf("Binary search in sorted array started...\n");
		time_start = clock();
		k = binary_search(value, array_size, array);
		time_end = clock();
		time_sort = (time_end - time_start)/CLOCKS_PER_SEC;
		printf("Binary search in sorted array finished.\n");
		
		if(time_sort < 10000)
			fprintf(file, "Binary search\t\t%.18lf sec\t\t", time_sort);
		else
			fprintf(file, "Binary search\t\t%.18lf sec\t", time_sort);
		
		if(array_size < 1000)
			fprintf(file, "%i\t\t\tSorted\t\t\t\t", array_size);
		else
			fprintf(file, "%i\t\tSorted\t\t\t\t", array_size);
		
		if(value < 1000)
			fprintf(file, "%i\t\t\t", value);
		else
			fprintf(file, "%i\t\t", value);
		
		if(k >= 0)
			fprintf(file, "%i\n", k);
		else
			fprintf(file, "Not founded!\n");
		
		if(typesearch)
			break;
		}
	}
}
