#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include <string.h>

#include "dk_tool.h"
#include "Sort.h"

int main() {
    int long_array=1;

    Square_Triangle *Array_Square=(Square_Triangle *)malloc(long_array * sizeof(Square_Triangle));

    if (NULL == Array_Square) {
        printf("Error of memory Square");
        return 0;
    }

    Square_Triangle *Temp_Array_Square=(Square_Triangle *)malloc(long_array * sizeof(Square_Triangle));

    if (NULL == Temp_Array_Square) {
        printf("Error of memory Square, Temp");
        free(Array_Square);
        return 0;
    }

    triangle_str *Triangle = (triangle_str *) malloc(long_array * sizeof(triangle_str));

    if (NULL == Triangle) {
        printf("Error of memory Triangle");
        free(Array_Square);
        free(Temp_Array_Square);
        return 0;
    }

    memset(Triangle, 0, long_array * sizeof(triangle_str));

//make file
    FILE *File_main = fopen("data.json", "w+");

    if (NULL == File_main) {
        printf("Error of file data");
        free(Array_Square);
        free(Triangle);
        free(Temp_Array_Square);
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
        Array_Square[i].Square=S;
        Array_Square[i].index=i;
        printf("Rezalt number triangle %i: %f\n", i, S);
    }

    overstore_array(Array_Square, Temp_Array_Square, long_array);

    Write_all(File_main, long_array, Triangle);

    for (int i = 0; i < 4; ++i) {
        char *name_file = malloc(30 * sizeof(char));
        switch (i) {
            case 0: {
                //BUBBLE
                sort_bubble(Temp_Array_Square, long_array);
                strcpy(name_file,"sort_bubble.json");
                break;
            }
            case 1: {
                //selection
                sort_insert(Temp_Array_Square, long_array);
                strcpy(name_file,"sort_selection.json");
                break;
            }
            case 2: {
                //insert
                sort_selection(Temp_Array_Square, long_array);
                strcpy(name_file,"sort_insert.json");
                break;
            }
            case 3: {
                //Shell
                sort_Shell(Temp_Array_Square, long_array);
                strcpy(name_file,"sort_Shell.json");
                break;
            }
        }
        FILE *File_sort= fopen(name_file, "w+");
        if (NULL == File_sort) {
            printf("Error of file sort");
            free(Array_Square);
            free(File_main);
            free(Triangle);
            free(Temp_Array_Square);
            return 0;
        }
        Write_all_sort(File_sort, long_array, Triangle, Temp_Array_Square);
        overstore_array(Array_Square, Temp_Array_Square, long_array);

        fflush(File_sort);
        fclose(File_sort);
        free(name_file);
    }

    free (Triangle);
    free(Array_Square);

//    clouse file
    fflush(File_main);
    fclose(File_main);

    //write adress current dir
    char *dir_current = malloc(100* sizeof(char));
    if (getcwd(dir_current, 100* sizeof(char))!=NULL)
        printf("Data is recorded in files %s\n%s\n", dir_current, "Name: data.json, sort_bubble.json, sort_selection.json, sort_insert.json, sort_Shell.json");

    free(dir_current);

    return 0;
}