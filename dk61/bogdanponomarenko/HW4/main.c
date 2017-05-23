
#include "sort.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "t.h"

int main()
{
    unsigned int aSize = 0;
	 int sort = 0;

    printf("Number of rectangles :  ");

    scanf(" %d",&aSize);

    FILE *aFile = fopen("data.json", "w");


    ListFigures * figure = CreateListFigure(aSize);
    for (int i = 0; i < aSize; i++)
    {
        AddRectangle(figure);
    }


    printf("What kind of sorting do you want to use? \n");
    printf("1 -----  BubbleSort\n");
    printf("2 -----  SelectionSort\n");
    printf("3 ----- InsertionSort\n");

    scanf("\t \t  %d", &sort);

	printf("------BEFORE SORTING------\n");
	printRectangleList(figure);
			
				
    switch (sort) {
        case 1:
            Bubble_Sort(figure);

            break;

        case 2:
            Selection_Sort(figure);

            break;

        case 3:
            Insertion_Sort(figure);
            break;

        default:
            printf("Number from 1 to 3");
    }
    printf("-----AFTER SORTING-----\n \n");

    printRectangleList(figure);

    writeList(aFile,figure);

    DestroyList(figure);

    _getch();

    return 0;
}

