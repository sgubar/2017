#include <stdio.h>
#include "t.h"
#include <stdlib.h>

int main() {

    ListFigures * figure = CreateListFigure(1);

    FILE *theFile = fopen("data.json", "w");

    AddRectangle(figure);

    PrintSquare(figure);

    writeList(theFile, figure);

    DestroyList(figure);

fflush(theFile);

    fclose(theFile);
    system ("pause");
    return 0;

}
