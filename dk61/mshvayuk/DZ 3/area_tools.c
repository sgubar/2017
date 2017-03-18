#include "area_tools.h"
#include <math.h>

float scan(int min, int max)
{
	
	float buffer;// variable for saving that what we scanned
	int q;// variable for checking on idiot
	do
	{
	q = scanf("%f", &buffer);
	
	fflush(stdin);// without this it willn't work correctly
	
	if((buffer<min || buffer>max) || q!=1)
	{
		printf("\ngive me the correct number pls!");	
	}		
	
	}
	
	while ((buffer<min || buffer>max) || q!=1);
	
	return buffer;	

}

void scan_dot( point *masiv)// make massiv of structures
{
	
	char name[4] = {'A' , 'B', 'C', 'D'};
	
	int i = 0;//counter for loop
	
	for(i; i<4; i++ )
	{
		printf("\n give me the %c point X coordinate (-1000; 1000): ", name[i]);
		masiv[i].x = scan(-1000, 1000);
		
		printf("\n give me the %c point Y coordinate (-1000; 1000): ", name[i]);
		masiv[i].y = scan(-1000, 1000);
		
	}
		printf("\n your dots have those coordinates: \n A (% .2f;% .2f)\n B (% .2f;% .2f)\n C (% .2f;% .2f) \n D (% .2f;% .2f)",masiv[0].x, masiv[0].y, masiv[1].x, masiv[1].y, masiv[2].x,masiv[2].y, masiv[3].x, masiv[3].y );
	
}

float area(point *masiv )
 {
 //     A = masiv[0]
// 		B = masiv[1]
// 		C = masiv[2]
// 		D = masiv[3]

		float A_x = masiv[0].x;// tak zruchnishe provoditi rozrachunky
		float A_y = masiv[0].y;
		float B_x = masiv[1].x;
		float B_y = masiv[1].y;
		float C_x = masiv[2].x;
		float C_y = masiv[2].y;
		float D_x = masiv[3].x;
		float D_y = masiv[3].y;
 		
 		float AC, BD;//variables for lenght of diagonals 
		//find them with formula vidstani mizh 2 tochkami
		
		AC = sqrt((C_x - A_x)*(C_x - A_x) + (C_y - A_y)*(C_y - A_y));
		printf("\n\n the lenght of AC  diagonal is % .2f \n", AC);
		
		BD = sqrt((D_x - B_x)*(D_x - B_x) + (D_y - B_y)*(D_y - B_y));
		printf("\n the lenght of BD  diagonal is % .2f \n", BD);
		
		struct dot vektor_ac;//create VEKTORS     ac     and    bd
		struct dot vektor_bd;
		
		vektor_ac.x = (C_x - A_x);//first coordinate of vektor ac
		vektor_ac.y = (C_y - A_y);//second coordinate of vektor ac
		printf("\n\n your vektor     ac    has koordinates:   ( % .2f ; % .2f ) \n",vektor_ac.x, vektor_ac.y );
	 
	 	vektor_bd.x = (D_x - B_x);//first coordinate of vektor bd
		vektor_bd.y = (D_y - B_y);//second coordinate of vektor bd
		printf("\n your vektor     bd    has koordinates:   ( % .2f ; % .2f ) \n",vektor_bd.x, vektor_bd.y );
	 	
	 	
		float ac_bd;//count the scalar derivative (dobutok) of vektors 		ac 		and 		bd
		ac_bd = ( (vektor_ac.x * vektor_bd.x) + (	vektor_ac.y * 	vektor_bd.y) );
		printf("\n\n scalar dobutok   ac * bd   =   % .2f\n",ac_bd);
		
		// count the cos(a) = ac_bd / (AC * BD)
		float cos_a;//cosinus  of wanted angle (ugol)
		cos_a = ac_bd/(AC*BD);
		printf("\n\n the cos(a) = % .2f\n",cos_a);
		
		//count the area with formula plochi opuklogo 4-kutnika
		float S;//variable for area
		S = (AC * BD) / (2 * cos_a);
		
		return S;
		
 }
 
void json_write( FILE *file, point *masiv)
{
	char name[4] = {'A', 'B', 'C', 'D'};
	int j = 0;//counter for loop
	
	fprintf(file, "{\n\"masiv_dots\":\n[\n");
	
	for(j; j<4; j++)
	{
		fprintf(file, "\"%c\": {\"X\": % .2f, \"Y\": % .2f,},\n", name[j], masiv[j].x, masiv[j].y);
	}
	
	fprintf(file,"]\n}");
	
	fflush(file);//something with buffer, corotche tak nado delat
				 //PROTALKIVAEM BUFFER V FILE ESLI PROGRAMA SLOMALAS
	fclose(file);
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


 

