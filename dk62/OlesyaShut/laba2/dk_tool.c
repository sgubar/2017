#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dk_tool.h"
#include "sort.h"

void fill_Array(int *aArray, int aSize)
{
	srand(time(NULL));										//создание "ключа" для генератора случайных чисел. используем текущее время на компьютере в секундах
	int i;
	for(i = 0; i < aSize; i++)
		aArray[i] = rand() % 10001;							//элемент массива[i] = остача от деления случайного числа на 10001 были (чтобы числа были от 0 до 10000)
}

void sorting(int *aArray, int aSize)
{
	FILE *file = fopen("Result.txt", "w");					//создаем указатель на файл file, функцией fopen открываем файл "Result.txt" для записи "w"
	if(file == NULL)										//указатель равен нулю, если файла нет. поскольку файл для записи, то его не создало/не открыло
	{
		printf("File lost!\n");
		free(aArray);
		exit(-2);											//выход из программы со значением -2 (return -2;)
	}
	
	fprintf(file, "Size of array: %i\n\n", aSize);
	
	clock_t start, finish;									//clock_t - тип данных время в милисекундах
	double result;											//сюда запишем разницу во времени до начала сортировки и после её окончания - результат
	
	fill_Array(aArray, aSize);								//заполнение массива случайными числами от 0 до 10000
	
	start = clock();										//записываем время до начала сортировки в милисекундах
	bubblesort(aArray, aSize);
	finish = clock();										//после сортировки
	
	result = (finish - start)/CLOCKS_PER_SEC;				//(конец - начало)/1000
	printf("Bubblesort finished\n");
	fprintf(file, "Bubblesort\t\t\t%.18lf sec\n", result);	//записываем в файл название сортировки и время (%.18lf) 18 знаков после ,
	
	
	fill_Array(aArray, aSize);								//снова заполняем массив случайными числами
	
	start = clock();
	insertionsort(aArray, aSize);
	finish = clock();
	
	result = (finish - start)/CLOCKS_PER_SEC;
	printf("Insertionsort finished\n");
	fprintf(file, "Insertionsort\t\t%.18lf sec\n", result);
	
	
	fill_Array(aArray, aSize);
	
	start = clock();
	selectionsort(aArray, aSize);
	finish = clock();
	
	result = (finish - start)/CLOCKS_PER_SEC;
	printf("Selectionsort finished\n");
	fprintf(file, "Selectionsort\t\t%.18lf sec\n", result);
	
	fflush(file);
	fclose(file);
}
