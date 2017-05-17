#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jab3.h"

int main(void)
{
    FILE *txt_file = fopen("Text.txt" , "rt");
    if(txt_file == NULL)
    {
        printf("No such file found");
        return -1;
    }
    else
        printf("File opened\n");

    fseek (txt_file, 0, SEEK_END);
    int length = ftell(txt_file);
	fclose(txt_file);
    printf("Length of file: %i elements\n" , length);

    FILE *txt_file1 = fopen("Text.txt" , "rt");


	char *buffer = (char*)malloc(sizeof(char) * length );
    fgets(buffer, length, txt_file1);
    fclose(txt_file1);
    getch();
    printf("Select type of sort:\n 1.Bubble Sort\n 2.Insertion Sort\n 3.Selection Sort\n 4.Shell Sort\n ");
    int type_of_sort = 0;
    scanf("%i" , &type_of_sort);
    if ((type_of_sort == 1) || (type_of_sort == 2) || (type_of_sort == 3) || (type_of_sort == 4))
    {
        clock_t start = clock();


         switch(type_of_sort)
        {
            case 1:
            BubbleSort ( buffer , length);
            break;

            case 2:
            InsertionSort ( buffer , length);
            break;

            case 3:
            SelectionSort(length , buffer);
            break;

            case 4:
            ShellSort( buffer , length);
            break;


        }
        clock_t end = clock();
        float time1 = end - start;
        printf("Time sorting: %0.10f\n", time1/CLOCKS_PER_SEC);

    }
    else
        {
            printf("Wrong! Select type of sort again!\n");
            return type_of_sort;
        }

    char search;
    printf("Enter symbol which you want search:");
    gets(search);
    int result = BinarySearch(length, buffer, search);
    printf("\nPosition of searching symbol:%d", result);

    FILE *file = fopen("D:/Vlad/Text_sort.txt","wt");
	int i = 0;
	while(i<length)
	{
		putc((int)buffer[i],file);
		i++;
	}
	fclose(file);

    free(buffer);
	return 0;

}

