#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Node.h"

int main(void) {
    list buf;
    char *text = malloc(sizeof(char)*1000);
    do{
        printf("Hello. Please give the name of the file without indicating file type.\n");
        scanf("%s",&text);
        int str = strlen((text));
        text[str+1] = 't';
        text[str+2] = 'x';
        text[str+3] = 't';
        text[str+4] = '\0';
    }while (!fBuff(text,&buf));
    char *symmetr = (ISsymetry(&buf) ? "symmetrical" : "non symetrical");
    printf("Text in this file is %s.\n",symmetr);
    return 0;
}