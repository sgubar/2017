#include <stdbool.h>
#include "octo.h"

int power(int a,int b){
    int powered = 1;
    while(b > 0){
        powered *= a;
        b--;
    }
    return powered;
}
bool OctoCheck(char c[],int n){
    for (int i = 0; i < n-1; ++i){
        if ((c[i] > '7' || c[i] < '0')){
            return false;
        }
    }
    return true;
}
int OtoD(char octal[],int n){
    int decimal = octal[n-1]-48;
    for (int i = 0;  i < n-1; ++ i){
        decimal += (octal[i] -48)*power(8,n-i-1);
    }
    return decimal;
}