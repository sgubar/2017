#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>

#include "dk_tool.h"

int main() {

    setlocale(LC_ALL, "Rus");

    FILE *f_save = fopen("Table.csv","w+");
    int *array_main;
    int *array_sort;
    int time;
    int i;

    if (NULL==f_save)
    {
        printf("Ошибка, переполнение памяти в файле.\n");
        return 0;
    }

    int msize=scanSize();
    array_main=malloc(msize* sizeof(int));

    if (NULL==array_main)
    {
        printf("Ошибка, переполнение памяти в файле.\n");
        return 0;
    }

    array_sort=malloc(msize* sizeof(int));
    if (NULL==array_sort)
    {
        free(array_main);
        printf("Ошибка, переполнение памяти в файле.\n");
        return 0;
    }

    makeHeaderFile(f_save);

    generation(array_main, msize);

    writeInFile(f_save, 2, msize, array_main);

    for (i = 3; i < 8; ++i) {
        overstoreArray(array_main, array_sort, msize);
        time=clock();

        switch (i)
        {
            case 3:
            {
                bubbleSort(array_sort, msize);
                break;
            }
            case 4:
            {
                selectionSort(array_sort, msize);
                break;
            }
            case 5:
            {
                insertSort(array_sort, msize);
                break;
            }
            case 6:
            {
                shellSort(array_sort, msize);
                break;
            }
            case 7:
            {
                quickSort(array_sort, 0, msize);
                break;
            }
        }
        time=clock()-time;
        writeTime(f_save, i, time);
        writeInFile(f_save, i, msize, array_sort);
    }

    makeFutterFile(f_save);
    fclose(f_save);

    char *dir_current = malloc(100* sizeof(char));
    if (getcwd(dir_current, 100* sizeof(char))!=NULL)
    printf("Данные записаны в файл %s\n%s\n", dir_current, "Имя файла: Table.csv");

    free(dir_current);
    free(array_main);
    free(array_sort);

    return 0;
}
