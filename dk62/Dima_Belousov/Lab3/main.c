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
    int time;
    if (NULL==f_save)
    {
        printf("Ошибка, переполнение памяти в файле.\n");
        return 0;
    }

    int msize=scanSize("размер массива");
    array_main=malloc(msize* sizeof(int));

    if (NULL==array_main)
    {
        printf("Ошибка, переполнение памяти в файле.\n");
        return 0;
    }

    makeHeaderFile(f_save);

    generation(array_main, msize);

    writeInFile(f_save, 2, msize, array_main);

    time=clock();

    quickSort(array_main, 0, msize);

    time=clock()-time;
    writeTime(f_save, 3, time);
    writeInFile(f_save, 3, msize, array_main);

    makeFutterFile(f_save);
    fclose(f_save);

    char *dir_current = malloc(100* sizeof(char));
    if (getcwd(dir_current, 100* sizeof(char))!=NULL)
    printf("Данные записаны в файл %s\n%s\n", dir_current, "Имя файла: Table.csv");

    int search_element = scanSize("элемент поиска");
    linearSearch(array_main, search_element, msize);

    free(dir_current);
    free(array_main);

    return 0;
}
