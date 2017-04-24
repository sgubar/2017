#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"
#include "dk_tool.h"
#include "searches.h"
#include "cor_types.h"

int main(int argc, const char *argv[])
{
int array_size, typetest, typevalues, typeval_similar = 0, typeval_false = 0, typesearch, typelin_arr = 10, value;

printf("Greetings! The program is designed to test the effectiveness of types of ");
printf("sorting and searching numbers 0-32767(99999).\n");
printf("\nWhen working, you can choose different options:\n1. The size of the array;\n2. Numbers for sorting;\n");
printf("3. Verification of a particular type of sorting, or all;\n4. Type of searching;\n5. Value to search;\n");
printf("\nThe program supports sorting types:\n1. bubble sort;\n2. merge sort;\n");
printf("3. insertion sort;\n4. selection sort;\n5. shell sort;\n6. quick sort;\n");
printf("\nThe program supports searching types:\n1. line search;\n2. binary search;\n\n");

enter_values(&array_size, &typetest, &typevalues, &typeval_similar, &typeval_false, &typesearch, &typelin_arr, &value);

int *array = (int *) malloc(sizeof(int) * array_size);
if(!array)
	{
	printf("Memory Error!!!\n");
	exit(1);
	}

int *sec_array = (int *) malloc(sizeof(int) * array_size);
if(!sec_array)
	{
	printf("Memory Error!!!\n");
	free(array);
	exit(2);
	}

FILE *file = fopen("Results.txt", "w");
if(!file)
	{
	printf("File Error!!!\n");
	free(array);
	free(sec_array);
	exit(3);
	}

array_fill_values(array, array_size, typevalues, typeval_similar, typeval_false);
copy_values(sec_array, array, array_size);

array_sort(file, array, sec_array, array_size, typetest, typevalues, typeval_similar, typeval_false);

array_search(file, array, sec_array, array_size, typesearch, typelin_arr, value);

fflush(file);
fclose(file);

free(sec_array);
free(array);

system("pause");
return 0;
}

