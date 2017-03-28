#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>

#include "Write.h"
#include "Sort.h"
#include "Find.h"


int main() {

    FILE *f_save = fopen("Tabl.csv","w+");
    int *array_main;
    int time;
    if (NULL==f_save)
    {
        printf("Error, memory overflow in file.\n");
        return 0;
    }
    //array's size
    int msize=scan_size("the size of the array");
    array_main=malloc(msize* sizeof(int));

    if (NULL==array_main)
    {
        printf("Error, memory overflow.\n");
        return 0;
    }

    //makefile(f_save);

    make_heder_file(f_save);

    generation(array_main, msize); //generation array

    Write_in_file(f_save, 2, msize, array_main);

    time=clock();

    sort_QuickSort(array_main, 0, msize);

    time=clock()-time;
    Write_time(f_save, 3, time);
    Write_in_file(f_save, 3, msize, array_main);

    //closing the file
    make_futter_file(f_save);
    fclose(f_save);

    //write adress current dir
    char *dir_current = malloc(100* sizeof(char));
    if (getcwd(dir_current, 100* sizeof(char))!=NULL)
    printf("Data is recorded in files %s\n%s\n", dir_current, "Name: Tabl.csv");

    //search
    int search_element = scan_size("element search");
    lion_search(array_main, search_element, msize);

    //deallocation
    free(dir_current);
    free(array_main);

    return 0;
}
