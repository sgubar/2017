#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "DK_tool.h"
#include "Sort.h"

int main() {
    int long_array=3;

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
        printf("Rezalt sqere number triangle %i: %.4f\n", i, S);
    }

    overstore_array(Array_Square, Temp_Array_Square, long_array);

    //запись основного файла
    Write_all(File_main, long_array, Triangle);

    //сортировки
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
        //Write_all_sort(File_sort, long_array, Triangle, Temp_Array_Square);
        fprintf (File_sort, "{\n\"Triangls\" : [\n");
        for (int i = 0; i < long_array; ++i) {
            write_triangle(File_sort, Triangle[Temp_Array_Square[i].index], Temp_Array_Square[i].index, long_array);
        }

        fprintf (File_sort, "]\n}\n");
        overstore_array(Array_Square, Temp_Array_Square, long_array);

        //освобождение памяти
        fflush(File_sort);
        fclose(File_sort);
        free(name_file);
    }

    char i_find;
    float j_find;
    do {
        printf("You need to find the element answer Y (Yes) or N (No)\n");
        i_find = scanf_char();
        if (i_find == 'Y') {
            printf("Enter the required area: \n");
            j_find = read_tru(0, 100000);
            lion_search(Temp_Array_Square, j_find, long_array, Triangle);
        } else break;

    }
    while (1);
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