#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>

#include "dk_tool.h"

int main() {
    int long_array=3;

    triangle_str *Triangle = (triangle_str *) malloc(long_array * sizeof(triangle_str));

    if (NULL == Triangle) {
        printf("Error of memory");
        return 0;
    }

    memset(Triangle, 0, long_array * sizeof(triangle_str));

//make file
    FILE *File_main = fopen("data.json", "w+");

    if (NULL == File_main) {
        printf("Error of file");
        free(Triangle);
        return 0;
    }

    for (int j = 0; j < long_array; ++j) {
        read_coor(&Triangle[j].A_Vertex, 'A', j);
        //read_coor(Triangle, 'A', j);
        read_coor(&Triangle[j].B_Vertex, 'B', j);
        read_coor(&Triangle[j].C_Vertex, 'C', j);
    }

    for (int i = 0; i < long_array; ++i) {
        print_triangl(&Triangle[i].A_Vertex, 'A', i);
        print_triangl(&Triangle[i].B_Vertex, 'B', i);
        print_triangl(&Triangle[i].C_Vertex, 'C', i);
    }

    // arow file
    for (int i = 0; i < long_array; ++i) {
        float S = calculate(Triangle[i].A_Vertex, Triangle[i].B_Vertex, Triangle[i].C_Vertex);
        printf("Rezalt number triangle %i: %f\n", i, S);
    }



    Write_all(File_main, long_array, Triangle);

    if (NULL != Triangle) {
        free (Triangle);
    }

//    clouse file
    fflush(File_main);
    fclose(File_main);

    //write adress current dir
    char *dir_current = malloc(100* sizeof(char));
    if (getcwd(dir_current, 100* sizeof(char))!=NULL)
        printf("Data is recorded in files %s\n%s\n", dir_current, "Name: data.json");

    free(dir_current);

    return 0;
}