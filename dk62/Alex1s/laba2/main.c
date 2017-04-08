#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "dk_tool.h"
#include "cor_types.h"

int main(int argc, char *argv[])
{
int array_size, typetest, typevalues, typeval_similar, typeval_false;

printf("Greetings! The program is designed to test the effectiveness of types of sorting numbers 0-32767(99999).\n");
printf("\nWhen working, you can choose different options:\n1. The size of the array;\n2. Numbers for sorting;\n");
printf("3. Verification of a particular type of sorting, or all;\n");
printf("\nThe program supports sorting types:\n1. bubble sort;\n2. merge sort;\n");
printf("3. insertion sort;\n4. selection sort;\n5. shell sort;\n6. quick sort;\n\n");

enter_values(&array_size, &typetest, &typevalues, &typeval_similar, &typeval_false);

int *array = (int *) malloc(sizeof(int) * array_size);
if(!array)
	{
	printf("Memory Error!!!\n");
	free(array);
	exit (1);
	}

array_fill_values(array, array_size, typevalues, typeval_similar, typeval_false);

array_sort(array, array_size, typetest, typevalues, typeval_similar, typeval_false);

print_array(array, array_size);
free(array);
system("pause");
return 0;
}
