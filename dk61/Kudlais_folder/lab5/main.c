#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <string.h>
int main(void) {
    tree info;
    char buffer[100];
    printf("Please write the numbers\n");
    scanf("%s", &buffer);
    // char *now = malloc(sizeof(char)*100);
    char new[100];
    for (int i, j = 0; i < strlen(buffer); ++i) {
        if (buffer[i] != ' ' && buffer[i] != '\n') {
            new[j] = buffer[i];
            j++;
        }
    }
    printf("%s", &new);
    return 0;
}