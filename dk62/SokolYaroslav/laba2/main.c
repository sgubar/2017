#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "lab2dk_tool.h"
#include "lab2dk_tool.c"

int main(void)
{
    int kolelement=0,kolslov=0;
    int n=3;
    //char element[3], slov[3];
    printf("Введіть кількість введених слів: ");
    kolslov=inputint(kolslov,n);
    printf("Введіть кількість введених букв: ");
    kolelement=inputint(kolelement,n);
    char slovoelement [kolslov][kolelement];
    printf("\nСгенеровані слова: \n");

    int ltime = time (NULL);
    int stime = ltime/2;
    srand(stime);
    generate(kolslov,kolelement,slovoelement);   
    
    buble(kolslov,kolelement,slovoelement);
    printf("rezult: ");
    pechat(kolslov,kolelement,slovoelement);

    
    
}

