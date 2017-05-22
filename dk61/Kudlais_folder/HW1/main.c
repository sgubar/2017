#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "octo.h"
int main(void) {
    char oct[5];
    bool key = false;
    while (!key) {
        printf("Please type octal number.\nEach digit of the octal number can have value between 0 and 7.\n");
        scanf("%4s", &oct);
        key = OctoCheck(oct,strlen(oct));
    }
    printf("Octal number is %s.\n",oct);
    int dec = OtoD(oct,strlen(oct));
    printf(" And decimal number is %i.",dec);
    return 0;

}