#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "lab2dk_tool.h"
#include "lab2dk_tool.c"

int main(void)
{
    int kolelement=0,kolslov=0, n=4;
    printf("Введіть кількість введених слів(від 1 до 999): ");
    kolslov=inputint(kolslov,n);
    printf("Введіть кількість введених букв(від 1 до 999): ");
    kolelement=inputint(kolelement,n);
    char slovoelement [kolslov][kolelement];
    
    generatestring(kolslov,kolelement,slovoelement);   
 
    printf("\nСгенеровані слова: ");
    print(kolslov,kolelement,slovoelement);
    //fprint(kolslov,kolelement,slovoelement);
    float start_time =  clock(); 
    bublesort(kolslov,kolelement,slovoelement);
    float end_time = clock();
    
    printf("\nВідсортовані сгенеровані слова: ");
    print(kolslov,kolelement,slovoelement);
    printf("\nДля відсортування методом бульбашки було витрачено часу:%f\n",(end_time - start_time)/CLOCKS_PER_SEC);

////*file
    kolelement=0,kolslov=0;
    kolelement=razmerf(kolelement);
    kolslov=kolslovf(kolelement,kolslov);
    char fstring [kolslov][kolelement]; 
    filestingr(kolelement,kolslov,fstring);
    printf("\nТекст з файлу: ");
    printfile(kolslov,kolelement,fstring);
    bublesort(kolslov,kolelement,fstring);
    printf("\nВідсортований текст з файлу: ");
    printfile(kolslov,kolelement,fstring);
    printinf(kolslov,kolelement,fstring);
}

