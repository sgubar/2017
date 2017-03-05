#include <stdio.h>
#include <malloc.h>
#include <time.h>

#include "Write.h"
#include "array.h"


int main() {

    FILE *f_save = fopen("iii.csv","w+");
    int *array_main;
    int *array_sort;
    int time;
    if (NULL==f_save)
    {
        printf("Error, memory overflow in file.");
        return 0;
    }
    //array's size
    int msize=scan_size();
    array_main=malloc(msize* sizeof(int));
    array_sort=malloc(msize* sizeof(int));

    if (NULL==array_main || NULL==array_sort)
    {
        printf("Error, memory overflow.");
        return 0;
    }
    //makefile(f_save);

    make_heder_file(f_save);

    generation(array_main, msize); //generation array

    Write_in_file(f_save, 2, msize, array_main);

    for (int i = 3; i < 8; ++i) {
        overstore_array(array_main, array_sort, msize); //copy the array to sort array
        time=clock();
        switch (i)
        {
            case 3:
            {
                sort_bubble(array_sort, msize);
                break;
            }
            case 4:
            {
                sort_selection(array_sort, msize);
                break;
            }
            case 5:
            {
                sort_insert(array_sort, msize);
                break;
            }
            case 6:
            {
                sort_Shell(array_sort, msize);
                break;
            }
            case 7:
            {
                sort_QuickSort(array_sort, 0, msize);
                break;
            }
        }
        time=clock()-time;
        Write_time(f_save, i, time);
        Write_in_file(f_save, i, msize, array_sort);
    }


//    //The record is not sorted array
//    Write_in_file(f_save, 2, msize, array_main);
//
//    //entry array method bubble
//    overstore_array(array_main, array_sort, msize); //copy the array to sort array
//    time=clock();
//    sort_bubble(array_sort, msize);
//    time=clock()-time;
//    Write_time(f_save, 3, time);
//    Write_in_file(f_save, 3, msize, array_sort);
//
//    //entry array method selection
//    overstore_array(array_main, array_sort, msize); //copy the array to sort array
//    time=clock();
//    sort_selection(array_sort, msize);
//    time=clock()-time;
//    Write_time(f_save, 4, time);
//    Write_in_file(f_save, 4, msize, array_sort);
//
//    //entry array method insert
//    overstore_array(array_main, array_sort, msize); //copy the array to sort array
//    time=clock();
//    sort_insert(array_sort, msize);
//    time=clock()-time;
//    Write_time(f_save, 5, time);
//    Write_in_file(f_save, 5, msize, array_sort);
//
//    //entry array method Shell
//    overstore_array(array_main, array_sort, msize); //copy the array to sort array
//    time=clock();
//    sort_Shell(array_sort, msize);
//    time=clock()-time;
//    Write_time(f_save, 6, time);
//    Write_in_file(f_save, 6, msize, array_sort);
//
//    //entry array method Quick Sort
//    overstore_array(array_main, array_sort, msize); //copy the array to sort array
//    time=clock();
//    sort_QuickSort(array_sort, 0, msize);
//    time=clock()-time;
//    Write_time(f_save, 7, time);
//    Write_in_file(f_save, 7, msize, array_sort);

    make_futter_file(f_save);
    closefile(f_save);

    return 0;
}
