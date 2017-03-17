/*** Чотирикутник, до складу якого входять 4 точки. Кожна точка задається двомірними 
координатами. 
Реалізувати функцію для обчислення площі. 
Надати функцію, що створює структуру за вхідними даними та додає її до масиву відповідних структур. 
*/

#include <stdio.h>
#include "area_tools.h"

int main(void)
{ 
	kvadrat();//printf an image of sqare
			
		point *masiv_dots = (point*)malloc(4 * sizeof(point));// make a massiv for all dots
		
		scan_dot(masiv_dots);
		
		float plaza = area(masiv_dots);// variable with area of figure
		
		printf("\n\n the area of your 4-corner is   % .2f \n", plaza);
		
}


