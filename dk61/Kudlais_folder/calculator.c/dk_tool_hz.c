#include "dk_tool_hz.h"
//  Змінення зроблені із врахуванням зауважень В'ячеслава Григоровича Губара
float power(int a, int b){ //функція, яка возводить int a в степінь int b
    float powered = a;// покращення взято з книги Б. Кернігана та Д. Рітчі "Мова програмування Сі". Можна не декларувати змінну-лічильник 
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
	else if(a < 0){
		int summed = 0;
		int i = 0;
		while(a < i){
			summed += power(2, a + i);
			i--;
		}
		return powered;
	}
	else{
		return 1;
	}
}
