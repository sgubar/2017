#include <stdio.h>
#include <cs50.h>
#include "dk_tools.h"

int main(void){
    int results [5]; // 5 використовується як приблизна кількість елеметнів, які потрібно отримати
    string s;
    bool acces = false;
    while(acces == false ){ //цикл не дає можливоті користувачеві вийти з нього, поки він не введе правильні значення
         printf("Take please 8 or more numbers which have 4 or less symbols without typing any letter:\n");
         s = GetString();
         int length = strlen(s);
         acces = check(s);
    }
    for(int k = 0; k < 5; k++){
        printf("%i\n",results[k]);
    }
}
