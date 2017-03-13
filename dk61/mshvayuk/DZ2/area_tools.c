#include "area_tools.h"
#include <math.h>

float area(float A_x, float A_y, float B_x, float B_y, float C_x, float C_y, float D_x, float D_y)
 {
 		float AC, BD;//variables for lenght of diagonals 
		//find them with formula vidstani mizh 2 tochkami
		
		AC = sqrt((C_x - A_x)*(C_x - A_x) + (C_y - A_y)*(C_y - A_y));
		printf("\n the lenght of AC  diagonal is % .2f \n", AC);
		
		BD = sqrt((D_x - B_x)*(D_x - B_x) + (D_y - B_y)*(D_y - B_y));
		printf("\n the lenght of BD  diagonal is % .2f \n", BD);
		
		struct dot vektor_ac;//create VEKTORS     ac     and    bd
		struct dot vektor_bd;
		
		vektor_ac.x = (C_x - A_x);//first coordinate of vektor ac
		vektor_ac.y = (C_y - A_y);//second coordinate of vektor ac
		printf("\n your vektor     ac    has koordinates:   ( % .2f ; % .2f ) \n",vektor_ac.x, vektor_ac.y );
	 
	 	vektor_bd.x = (D_x - B_x);//first coordinate of vektor bd
		vektor_bd.y = (D_y - B_y);//second coordinate of vektor bd
		printf("\n your vektor     bd    has koordinates:   ( % .2f ; % .2f ) \n",vektor_bd.x, vektor_bd.y );
	 	
	 	
		float ac_bd;//count the scalar derivative (dobutok) of vektors 		ac 		and 		bd
		ac_bd = ( (vektor_ac.x * vektor_bd.x) + (	vektor_ac.y * 	vektor_bd.y) );
		printf("\n scalar dobutok   ac * bd   =   % .2f\n",ac_bd);
		
		// count the cos(a) = ac_bd / (AC * BD)
		float cos_a;//cosinus  of wanted angle (ugol)
		cos_a = ac_bd/(AC*BD);
		printf("\n the cos(a) = % .2f\n",cos_a);
		
		//count the area with formula plochi opuklogo 4-kutnika
		float S;//variable for area
		S = (AC * BD) / (2 * cos_a);
		
		return S;
		
 }
 
 void kvadrat()
 {
	//print an image of square
	
	printf("this is how your square look like: \n\n");
	printf("B___________________C\n");
	int i;
	for(i = 0; i<7; i++)
	{
		printf("|                   |\n");
	}
	printf("A___________________D\n\n");
 
 
}
 

