#include <stdio.h>
#include "octal.h"
#define NUMBER_SIZE 4

int main(void) {
    char octal[NUMBER_SIZE];
    printf("Please type the octal number\nNotice: numbers from 1 to 7\n");
    GetOctal(octal, NUMBER_SIZE);
    for (int i = 0; i < NUMBER_SIZE; ++i) {
        printf("%c", octal[i]);
    }
    printf("\nIt was octal and now it gonna be decimal\n");
    int decimal = OtoD(octal, NUMBER_SIZE);
    printf("%i",decimal);
    return 0;
}