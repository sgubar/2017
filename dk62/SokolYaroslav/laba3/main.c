#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "lab3dk_tool.h"
#include "lab3dk_tool.c"
int main(void)
{
    int kel=razmerf();
    int ksl=kolslovf(kel);
    char slovo[ksl] [kel]; 
    filestingr(kel,ksl,slovo);
    printf("Текст з файлу: ");
    printfile(ksl,kel,slovo);
    float start=clock(); 
    quickSort(ksl,kel,slovo, 0,ksl-1);
    float end=clock();
    printf("============================\n");
    printf("Відсортований текст з файлу: ");
    printfile(ksl,kel,slovo);
    printinf(ksl,kel,slovo);
    printf("============================\n");
    printf("Витрачений час на сортування:%f\n",(end - start)/CLOCKS_PER_SEC);
    printf("============================\n");
    start=clock(); 
    int Result_of_serach = BinarySearch(ksl,kel,slovo,"bear ");
    end=clock();
    printf("Шукане слово знаходиться на місці:%i\n",Result_of_serach+1);
    printf("Витрачений час на пошук:%f\n",(end - start)/CLOCKS_PER_SEC);
}
