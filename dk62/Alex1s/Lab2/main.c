#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "dk_tool.h"

int main(int argc, char *argv[])
{
int rzmr, typetest, typevalues, typeval_similar, typeval_false;

printf("Greetings! The program is designed to test the effectiveness of types of sorting numbers 0-32767.\n");
printf("\nWhen working, you can choose different options:\n1. The size of the array;\n2. Numbers for sorting;\n3. Verification of a particular type of sorting, or all;\n");
printf("\nThe program supports sorting types:\n1. bubble sort;\n2. merge sort;\n3. insertion sort;\n4. selection sort;\n5. shell sort;\n6. quick sort;\n\n");

enter_values(&rzmr, &typetest, &typevalues, &typeval_similar, &typeval_false);

int *array = (int *) malloc(sizeof(int) * rzmr);

array_fill_values(array, rzmr, typevalues, typeval_similar, typeval_false);

array_sort_choose(array, rzmr, typetest);

//print_array(array, rzmr);

free(array);
system("pause");
return 0;
}
