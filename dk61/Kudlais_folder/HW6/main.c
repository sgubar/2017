#include <stdio.h>
#include "listing.h"
#include <stdlib.h>
#include <string.h>
int main(void) {
    list* buf;
    char *text = malloc(sizeof(char)*1000);
    printf("Hello. Please give the name of the file without indicating file type.\n");
    scanf("%s",text);
    int str = strlen((text));
    text[str+1] = 't';
    text[str+2] = 'x';
    text[str+3] = 't';
    text[str+4] = '\0';
    buf = fBuff(text);
    listsort(buf->Head,buf->Tail);
    Printlist(buf);
    return 0;
}