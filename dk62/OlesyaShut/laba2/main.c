#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "dk_tool.h"

#define ARRAY_SIZE 50000

int main(int argc, const char *argv[])
{
	int *Array = (int *) malloc(sizeof(int) * ARRAY_SIZE);		//выделение памяти на 50000 элементов
	if(Array == 0)												//если не выделило, указатель равен нулю
	{
		printf("Error!\n");
		return -1;
	}
	
	printf("Array created: %i elements.\n\n", ARRAY_SIZE);
	
	sorting(Array, ARRAY_SIZE);
	
	free(Array);												//освобождаем память
	return 0;
}
