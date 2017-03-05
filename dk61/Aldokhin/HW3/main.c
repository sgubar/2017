#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#include "dk_tool.h"

int main() {
    DK_coor *Triangle = (DK_coor *) malloc(3 * sizeof(DK_coor));
    if(NULL != Triangle)
    {
        memset(Triangle, 0, 3 * sizeof(DK_coor));
    }
//make file
    FILE *File_main = fopen("data.json", "w+");

    read_coor(Triangle);
// arow file
    float S=calculate(Triangle);
    printf("Rezalt: %f", S);
    if (NULL != Triangle) {
        free (Triangle);
    }

    write_Triangl(File_main, Triangle, S);

//    clouse file
    fflush(File_main);
    fclose(File_main);

    return 0;
}