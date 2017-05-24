#include <stdio.h>
#include "sort.h"
#include "t.h"


int main()
{
    int aSize = 0;
    int sort = 0;
    int value = 0;

    printf("Number of rectangles :  ");
    scanf(" %d",&aSize);

    ListFigures * figure = CreateListFigure(aSize);

    for (int i = 0; i < aSize; i++)
    {
        AddRectangle(figure);
    }

    sorting(figure);

    searching(figure,value);

    DestroyList(figure);

    return 0;
}

