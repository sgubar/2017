#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "dk_tool.h"

void enter_values(int *Arzmr, int *Atypetest, int *Atypevalues, int *Atypeval_similar, int *Atypeval_false)
{
int rzmr, typevalues, typetest, typeval_similar, typeval_false; 

do{
    printf("Enter amount of elements (between 10 and 100000).\nWarning!!! If you choose 100000 elements and bubblesort, you'll lose performanse of your PC.\n\nEnter: ");
    scanf("%i", &rzmr);
}while(rzmr < 10 || rzmr > 100000);
*Arzmr = rzmr;

do{
    printf("\nEnter number of type of sorting:\n0 - all types;\n1 - bubble;\n2 - merge;\n3 - insertion;\n4 - selection;\n5 - shell;\n6 - quick;\n\nEnter: ");
    scanf("%i", &typetest);
}while(typetest < 0 || typetest > 6);
*Atypetest = typetest;

do{
    printf("\nSelection of values:\n1. Several similar with choise of quantity;\n2. All random;\n3. Numbers in opposite order;\n4. Sorted array with one false number;\n\nEnter: ");
    scanf("%i", &typevalues);
}while(typevalues < 1 || typevalues > 4);
*Atypevalues = typevalues;

switch(typevalues)
{
	case 1:
	{
	do{
		printf("\nChoose quantity of similar numbers. You can't enter value larger then %i amount of elements. Enter: ", rzmr/5);
		scanf("%i", &typeval_similar);
	}while(typeval_similar < 2 || typeval_similar > rzmr/5);
	*Atypeval_similar = typeval_similar;
	break;
	}

	case 4:
	{
	do{
		printf("\nEnter number of location of false element:\n1 - first element;\n2 - center;\n3 - end of array;\n4 - random place;\n\nEnter: ");
		scanf("%i", &typeval_false);
	}while(typeval_false < 1 || typeval_false > 4);
	*Atypeval_false = typeval_false;
	break;
	}
}
}

//--------------------------------------------------------------------------------------------------------------------------------

void array_values_full_random(int *array, int rzmr)
{
srand(time(NULL));
int i;
for(i = 0; i < rzmr; i++)
	array[i] = rand();
}

//--------------------------------------------------------------------------------------------------------------------------------

void array_values_typeval_similar(int *array, int rzmr, int typeval_similar)
{
srand(time(NULL));
int i, tmp;
for(i = 0; i < rzmr; i++)
	{
	tmp = rand() % typeval_similar;
	array[i] = tmp;
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void array_values_opposite_order(int *array, int rzmr)
{
srand(time(NULL));
int i = rzmr;
for(i = 0; i < rzmr; i++)
	array[i] = rzmr - i - 1;
}

//--------------------------------------------------------------------------------------------------------------------------------

void array_values_typeval_false(int *array, int rzmr, int typeval_false)
{
srand(time(NULL));
int i;

switch(typeval_false)
{
	case 1:
	{
	array[0] = rand();
	for(i = 1; i < rzmr; i++)
		array[i] = i;
	break;
	}
	
	case 2:
	{
	int cen_ter = rzmr/2;
	array[cen_ter] = rand();
	for(i = 0; i < rzmr; i++)
		if(i != cen_ter)
			array[i] = i;
	break;
	}
	
	case 3:
	{
	int end = rzmr - 1;
	array[end] = rand();
	for(i = 0; i < end; i++)
		array[i] = i;
	break;
	}
	
	case 4:
	{
	int abc = rand() % rzmr;
	array[abc] = rand();
	for(i = 0; i < rzmr; i++)
		if(i != abc)
			array[i] = i;
	break;
	}
}
}

//--------------------------------------------------------------------------------------------------------------------------------

void array_fill_values(int *array, int rzmr, int typevalues, int typeval_similar, int typeval_false)
{
switch(typevalues)
	{
case 1:
	{
	array_values_typeval_similar(array, rzmr, typeval_similar);
	break;
	}
case 2:
	{
	array_values_full_random(array, rzmr);
	break;
	}
case 3:
	{
	array_values_opposite_order(array, rzmr);
	break;
	}
case 4:
	{
	array_values_typeval_false(array, rzmr, typeval_false);
	break;
	}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------

void array_sort_choose(int *array, int rzmr, int typetest)
{
clock_t time_start, time_end;

FILE* file = fopen("Results.txt", "w");
fprintf(file, "Result\t\t\t\tTime\n\n");
int *sec_array = (int *) malloc(sizeof(int) * rzmr);

switch(typetest)
	{
	case 0:
		{
		typetest++;
		}
	case 1:
		{
		printf("Bubble sort started.\n");
		time_start = clock();
		bubblesort(array, rzmr);
		time_end = clock();
		fprintf(file, "Bubblesort\t\t\t%.19lf sec\n", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		if(typetest)
			break;
		}
	case 2:
		{
		printf("Merge sort started.\n");
		time_start = clock();
		merge(rzmr, array, 0, rzmr - 1);
		time_end = clock();
		fprintf(file, "Mergesort\t\t\t%.19lf sec\n", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		if(typetest)
			break;
		}
	case 3:
		{
		printf("Insertion sort started.\n");
		time_start = clock();
		insertionsort(array, rzmr);
		time_end = clock();
		fprintf(file, "Insertionsort\t\t%.19lf sec\n", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		if(typetest)
			break;
		}
	case 4:
		{
		printf("Selection sort started.\n");
		time_start = clock();
		selectionsort(array, rzmr);
		time_end = clock();
		fprintf(file, "Selectionsort\t\t%.19lf sec\n", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		if(typetest)
			break;
		}
	case 5:
		{
		printf("Shell sort started.\n");
		time_start = clock();
		shellsort(array, rzmr);
		time_end = clock();
		fprintf(file, "Shellsort\t\t\t%.19lf sec\n", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		if(typetest)
			break;
		}
	case 6:
		{
		printf("Quick sort started.\n");
		time_start = clock();
		quicksort(array, 0, rzmr - 1);
		time_end = clock();
		fprintf(file, "Quicksort\t\t\t%.19lf sec\n", (double)(time_end - time_start)/CLOCKS_PER_SEC);
		if(typetest)
			break;
		}
	}
free(sec_array);
fflush(file);
fclose(file);
}

//--------------------------------------------------------------------------------------------------------------------------------


