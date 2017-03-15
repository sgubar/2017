#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dk_tools.h"

int main(void){
    int results [5]; // 5 використовується як приблизна кількість елеметнів, які потрібно отримати
    string str;
    bool acces = false;
    while(acces == false ){ //цикл не дає можливоті користувачеві вийти з нього, поки він не введе правильні значення
         printf("Take please 8 or more numbers which have 4 or less symbols without typing any letter:\n");
         scanf("%s",&str);
         int length = strlen(str);
         acces = check(str);
    }
    for(int k = 0; k < 5; k++){
        printf("%i\n",results[k]);
    }
}
