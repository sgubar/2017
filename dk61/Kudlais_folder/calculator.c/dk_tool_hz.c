#include "dk_tool_hz.h"

int power(int a, int b){ //функція, яка возводить int a в степінь int b
    int powered = a;
    int j = 0;
    while(j < b){
        powered = powered*a;
        j++;
    }
    return powered;
}
int sum(int a) { //функція для обчислення суми з i по a
	if(a > 0) { //перевірка на вірне значення
	    int summed = 0;
	    int i = 0;
        while(i < a){
		    summed += power(2, a + i);
		    i++;
	    }
	    return summed;
	}
	else{
		return 0;
	}
}