/*** Чотирикутник, до складу якого входять 4 точки. Кожна точка задається двомірними 
координатами. 
Реалізувати функцію для обчислення площі. 
Надати функцію, що створює структуру за вхідними даними та додає її до масиву відповідних структур. 
*/

#include <stdio.h>
#include<math.h>

void kvadrat();

struct dot {
	float x;//координаты Х и Y
	float y;
};

int main(void)
{ kvadrat();//друкує картинку квадрата
	
//	printf("you should give me 2 coordinates (X  and  Y)  for each dot( A B C D ) \n\n ");
	
	struct dot point_A;//наші 4 точки типу dot
	struct dot point_B;
	struct dot point_C;
	struct dot point_D;
	

	//	printf("give me the A dot X float coordinate = ");
	//	scanf("% f", &point_A.x);
	//	printf("\n give me the A dot Y float coordinate = ");
	//	scanf("% f", &point_A.y);
		
		point_A.x = 4.5;//координата  Х  точки   А
		point_A.y = 2.4;//координата  Y  точки   А
		printf("\n your A point has those coordinates: A(%.2f;%.2f)  \n",point_A.x, point_A.y );
		
		point_B.x = 3.7;
		point_B.y = 8.0;
		printf("\n your B point has those coordinates: B(%.2f;%.2f)  \n",point_B.x, point_B.y );
		
		point_C.x = 5.4;
		point_C.y = 4.2;
		printf("\n your A point has those coordinates: C(%.2f;%.2f)  \n",point_C.x, point_C.y );
		
		point_D.x = 6.8;
		point_D.y = 8.3;
		printf("\n your A point has those coordinates: D(%.2f;%.2f)  \n",point_D.x, point_D.y );

		
		float AC, BD;//змінні для довжини діагоналей
		//шукаємо за формулою відстані між 2 точками
		AC = sqrt((point_C.x - point_A.x)*(point_C.x - point_A.x) + (point_C.y - point_A.y)*(point_C.y - point_A.y));
		printf("\n the lenght of AC  diagonal is % .2f \n", AC);
		
		BD = sqrt((point_D.x - point_B.x)*(point_D.x - point_B.x) + (point_D.y - point_B.y)*(point_D.y - point_B.y));
		printf("\n the lenght of BD  diagonal is % .2f \n", BD);
		
		struct dot vektor_ac;//робимо вектори   ac   і    bd
		struct dot vektor_bd;
		
		vektor_ac.x = (point_C.x - point_A.x);//перша координата вектора ас
		vektor_ac.y = (point_C.y - point_A.y);//друга координата вектора ac
		printf("\n your vektor     ac    has koordinates:   ( % .2f ; % .2f ) \n",vektor_ac.x, vektor_ac.y );	 
	
		vektor_bd.x = (point_D.x - point_B.x);//перша координата вектора bd
		vektor_bd.y = (point_D.y - point_B.y);//друга координата вектора bd
		printf("\n your vektor     bd    has koordinates:   ( % .2f ; % .2f ) \n",vektor_bd.x, vektor_bd.y );
		
		float ac_bd;//шукаємо скалярний добуток векторів   ас   і   bd
		ac_bd = ( (vektor_ac.x * vektor_bd.x) + (	vektor_ac.y * 	vektor_bd.y) );
		printf("\n scalar dobutok   ac * bd   =   % .2f\n",ac_bd);
		
		// шукаэмо cos(a) = ac_bd/(AC * BD)
		float cos_a;//косинус шуканого кута
		cos_a = ac_bd/(AC*BD);
		printf("\n the cos(a) = % .2f\n",cos_a);
		
		//шукаємо площу за формулою площі опуклого чотирикутника
		float S;//змінна для прлощі
		S = (AC * BD) / (2 * cos_a);
		
		printf("\n the area of your 4-corner is   % .2f \n", S);
		
}

void kvadrat()
 {
	//друкує картинку квадрата
	
	printf("this is how your square look like: \n\n");
	printf("B___________________C\n");
	int i;
	for(i = 0; i<7; i++)
	{
		printf("|                   |\n");
	}
	printf("A___________________D\n\n");
	
	/*
 #include <stdio.h>
#include <string.h>

void print_arr(char a[], int n){
      for (int i=0; i<n; i++)
            printf("%c",a[i]);
      printf("\n");

}
int main(){
      char arr[]="kirill";
      int t=strlen(arr);
      print_arr(arr,t);
      return 0;
}
*/
}










