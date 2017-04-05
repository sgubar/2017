#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"
#include "dk_tool.h"

void enter_values(int *Aarray_size, int *Atypetest, int *Atypevalues, int *Atypeval_similar, int *Atypeval_false)
{
int array_size, typevalues, typetest, typeval_similar, typeval_false; 

do{
    printf("Enter amount of elements (between 10 and 100000).\n");
	printf("Warning!!! If you choose 100000 elements and bubblesort, you'll lose performanse of your PC.\n\nEnter: ");
    scanf("%i", &array_size);
}while(array_size < 10 /*|| array_size > 100002*/);
*Aarray_size = array_size;

do{
    printf("\nEnter number of type of sorting:\n0 - all types;\n1 - bubble;\n2 - merge;\n");
	printf("3 - insertion;\n4 - selection;\n5 - shell;\n6 - quick;\n\nEnter: ");
    scanf("%i", &typetest);
}while(typetest < 0 || typetest > 6);
*Atypetest = typetest;

do{
    printf("\nSelection of values:\n1. Several similar with choise of quantity;\n2. All random;\n");
	printf("3. Numbers in opposite order;\n4. Sorted array with one false number;\n\nEnter: ");
    scanf("%i", &typevalues);
}while(typevalues < 1 || typevalues > 4);
*Atypevalues = typevalues;

switch(typevalues)
{
	case 1:
	{
	do{
		printf("\nChoose quantity of similar numbers.");
		printf(" You can't enter value larger then %i amount of elements. Enter: ", array_size/5);
		scanf("%i", &typeval_similar);
	}while(typeval_similar < 2 || typeval_similar > array_size/5);
	*Atypeval_similar = typeval_similar;
	break;
	}

	case 4:
	{
	do{
		printf("\nEnter number of location of false element:\n1 - first element;");
		printf("\n2 - center;\n3 - end of array;\n4 - random place;\n\nEnter: ");
		scanf("%i", &typeval_false);
	}while(typeval_false < 1 || typeval_false > 4);
	*Atypeval_false = typeval_false;
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
srand(time(NULL));
int i = array_size;
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

void array_sort(int *array, int array_size, int typetest, int typevalues)
{
clock_t time_start, time_end;

char *sort = (char *) malloc(sizeof(char) * 40);

switch(typevalues)
	{
	case 1:
		{
		strcpy(sort, "Several similar with choise of quantity");
		break;
		}
	case 2:
		{
		strcpy(sort, "All random                             ");
		break;
		}
	case 3:
		{
		strcpy(sort, "Numbers in opposite order              ");
		break;
		}
	case 4:
		{
		strcpy(sort, "Sorted array with one false number     ");
		break;
		}
	}

FILE* file = fopen("Results.txt", "w");
fprintf(file, "Result\t\t\t\tTime\t\t\t\t\t\t\tArray\t\tType of unsorted array\n\n");

int *sec_array = (int *) malloc(sizeof(int) * array_size);
int i = typetest;
switch(i)
	{
	case 0:
		{
		i++;
		}
	case 1:
		{
		printf("Bubble sort started...\n");
		time_start = clock();
		bubblesort(array, array_size);
		time_end = clock();
		printf("Bubble sort finished.\n");
		fprintf(file, "Bubblesort\t\t\t%.18lf sec", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		fprintf(file, "\t\t%i\t\t%s\n", array_size, sort);
		if(typetest)
			break;
		}
	case 2:
		{
		printf("Merge sort started...\n");
		time_start = clock();
		merge(array_size, array, 0, array_size - 1);
		time_end = clock();
		printf("Merge sort finished.\n");
		fprintf(file, "Mergesort\t\t\t%.18lf sec", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		fprintf(file, "\t\t%i\t\t%s\n", array_size, sort);
		if(typetest)
			break;
		}
	case 3:
		{
		printf("Insertion sort started...\n");
		time_start = clock();
		insertionsort(array, array_size);
		time_end = clock();
		printf("Insertion sort finished.\n");
		fprintf(file, "Insertionsort\t\t%.18lf sec", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		fprintf(file, "\t\t%i\t\t%s\n", array_size, sort);
		if(typetest)
			break;
		}
	case 4:
		{
		printf("Selection sort started...\n");
		time_start = clock();
		selectionsort(array, array_size);
		time_end = clock();
		printf("Selection sort finished.\n");
		fprintf(file, "Selectionsort\t\t%.18lf sec", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		fprintf(file, "\t\t%i\t\t%s\n", array_size, sort);
		if(typetest)
			break;
		}
	case 5:
		{
		printf("Shell sort started...\n");
		time_start = clock();
		shellsort(array, array_size);
		time_end = clock();
		printf("Shell sort finished.\n");
		fprintf(file, "Shellsort\t\t\t%.18lf sec", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		fprintf(file, "\t\t%i\t\t%s\n", array_size, sort);
		if(typetest)
			break;
		}
	case 6:
		{
		printf("Quick sort started...\n");
		time_start = clock();
		quicksort(array, 0, array_size - 1);
		time_end = clock();
		printf("Quick sort finished.\n");
		fprintf(file, "Quicksort\t\t\t%.18lf sec", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		fprintf(file, "\t\t%i\t\t%s\n", array_size, sort);
		if(typetest)
			break;
		}
	}

free(sort);
free(sec_array);
fflush(file);
fclose(file);
}

//-----------------------------------------------------------------------------------------------------------


