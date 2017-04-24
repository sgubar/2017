#include <stdio.h>
#include "octal.h"

float power(int a, int b){
    float powered = a;
    if(b > 0) {
        while (b > 0) {
            powered = powered * a;
            --b;
        }
    }
    else if(b < 0) {
        while (b < 0) {
            powered = (float) powered / (float) a;
            ++b;
        }
        return powered;
    }
    else{
        return 1;
    }
}
void GetOctal(char c[],int n){
    for (int i = 0; i < n; ++i){
        scanf("%c", &c[i]);
        if(c[i] > 55 && c[i] < 48){
            printf("\nYou took incorrect value, please take correct one\n");
            --i;
        }
    }
}
int OtoD(char octal[],int n){
    int decimal = (int)octal[n-1] - 48;
    for (int i = 0;  i < n; ++ i){
        decimal += (octal[n-2-i] -48)*power(10, i);
    }
    return decimal;
}