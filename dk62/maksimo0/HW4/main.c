//
// Created by Max on 04.04.2017.
//

#include "dk_tool.h"
#include "sort.h"

int main(int argc, const char * argv[])
{
    FILE *TagFilE=fopen("JSON_file.json","w");

    printf("Vvedit rozmir spisku:");
    int RzmR;
    scanf("%i", &RzmR);

    SpskOfTrK *TagSpskOfTrK=StvorennyaSpsK(RzmR);

    addDani(TagSpskOfTrK, 43, 14, 5, 2, 6, 3);
    addDani(TagSpskOfTrK, 53, 64, 4, 5, 12, 3);
    addDani(TagSpskOfTrK, 6, 1, 55, 4, 5, 6);

    //BubbleSorT(TagSpskOfTrK);
    SelectionSorT(TagSpskOfTrK);
    //InsertionSorT(TagSpskOfTrK);

    Print(TagSpskOfTrK);

    WriteSpskOfTrK(TagFilE, TagSpskOfTrK);

    Vidalennya(TagSpskOfTrK);

    fflush(TagFilE);
    fclose(TagFilE);

    return 0;
}
