/*** Чотирикутник, до складу якого входять 4 точки. Кожна точка задається двомірними 
координатами. 
Реалізувати функцію для обчислення площі. 
Надати функцію, що створює структуру за вхідними даними та додає її до масиву відповідних структур. 
*/

#include <stdio.h>
#include"area_tools.h"

int main(void)
{ kvadrat();//друкує картинку квадрата
	
//	printf("you should give me 2 coordinates (X  and  Y)  for each dot( A B C D ) \n\n ");
	
	struct dot point_A;//наші 4 точки типу dot
	struct dot point_B;
	struct dot point_C;
	struct dot point_D;
	

		point_A.x = 4.5;//координата  Х  точки   А
		point_A.y = 2.4;//координата  Y  точки   А
		
	/*	printf("give me the A dot X float coordinate = ");
		scanf("% f", &point_A.x);
		printf("\n give me the A dot Y float coordinate = ");
		scanf("% f", &point_A.y); */
		
	//	point_A.x = 4.5;//координата  Х  точки   А
	//	point_A.y = 2.4;//координата  Y  точки   А
		printf("\n your A point has those coordinates: A(%.2f;%.2f)  \n",point_A.x, point_A.y );
		
		point_B.x = 3.3;
		point_B.y = 8.0;
		printf("\n your B point has those coordinates: B(%.2f;%.2f)  \n",point_B.x, point_B.y );
		
		point_C.x = 5.4;
		point_C.y = 4.2;
		printf("\n your A point has those coordinates: C(%.2f;%.2f)  \n",point_C.x, point_C.y );
		
		point_D.x = 6.8;
		point_D.y = 8.3;
		printf("\n your A point has those coordinates: D(%.2f;%.2f)  \n",point_D.x, point_D.y );
		
		float plaza = area(point_A.x,point_A.y,point_B.x,point_B.y,point_C.x,point_C.y,point_D.x,point_D.y );
		
		printf("\n the area of your 4-corner is   % .2f \n", plaza);
		
}


