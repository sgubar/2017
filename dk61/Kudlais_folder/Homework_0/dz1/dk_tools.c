#include "dk_tools.h"
#include <stdio.h>

bool check(string s, int *results){
    if(s != NULL){
        int counter_quantity = 0;  
        int counter_length = 0;
        int res_quant = 0;
        int cntr = 0;
        int number = 0;
        for(int i  = 0; i < length; i++){
            if(((int)s[i] <= 57 && (int)s[i] => 48) || (int)s[i] == 32){
                if((int)s[i] == 32 && i != 0){
                    counter_quantity++;
                    counter_length = 0;
                }
                if((int)s[i] <= 57 && (int)s[i] => 48){
                    counter_length++;
                }
                if(counter_length > 4){
                    printf("Your number is too long.\nPlease try again.");
                    return false;
                }
                if(counter_quantity == 7){
                    int number = 0;
                    cntr++;
                    if((int)s[i+1] == 32){
                        while(cntr > 0){
                            number = number + ((int)s[i] - 48) * power(10, cntr);
                        }
                        *(array + res_quant) = number;
                    }
                }    
            }
            else{
                printf("You typed the latter.\nPlease try again.");
                return false;
            }
        }
        return true;
    }
    else{
        printf("You did not take the numbers\n");
        return false;
    }
}
int power(int data, int n){
    int powered = data;
    for(int j = 0; j < n; j++){
        powered = powered*data;
    }
    return powered;
    
}
