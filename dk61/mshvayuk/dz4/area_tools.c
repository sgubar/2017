#include "area_tools.h"
#include <math.h>
#include "sort_tools.h"


SquareArray *create_square_array(int Asize)//create an ARRAY of KVADRATS
{
	SquareArray *masiv = malloc(sizeof(SquareArray)*Asize);
	
	if(NULL != masiv)
	{
		masiv->array = (Square*)malloc(sizeof(Square)*Asize);
				
		masiv->size = Asize;
		masiv->current_size =  0;
	}
}

void destroySquareArray(SquareArray *aList)//destroy an ARRAY of KVADRATS
{
	if(NULL != aList)
	{
		if (NULL != aList->array)
		{
			int i = 0;
			for(i; i<aList->current_size; i++)
			{
				Square theSquare = aList->array[i];
				if(NULL != theSquare.points)
				{
					free(theSquare.points);
				}
			}
		}
		free(aList);
	}
	
}

int addSquareToList(SquareArray *aList, Square *aSquare)// add a KVADRAT to ARRAY
{
	int the_return = 0;
	
	if(aList!= NULL && aSquare!=NULL)
	{
		if(aList->current_size < aList->size)
		{
			Square *figure = &(aList->array[aList->current_size]);

			int i=0;
			for(i;i<4;i++)
			{
				printf("\ngive me the square:%i, [%i].x ",aList->current_size, i);
				figure->points[i].x = scan(-1000, 1000);
				
				printf("\ngive me the square:%i, [%i].y ",aList->current_size, i);
				figure->points[i].y = scan(-1000, 1000);

			}

			aList->current_size++;

		}
		else
		{
			the_return = -2;
		}
	}
	else
	{
		the_return = -1;
	}
	return the_return;	
}

void addSeveralSquaresToList(SquareArray *aList, Square *aSquare)// add several KVADRATS into ARRAY using funk addSquareToList
{
	printf("\n how many SQUARES are there in array (min = 1, max = 15)? = ");
	int quantity = scan(1, 15);
	int i = 0;
	for(i;i<quantity; i++)
	{
		addSquareToList(aList, &aSquare);

	}
	
}


float area_square(SquareArray *ANarray)//calculate an area of KVADRAT
{
	int rozmir = ANarray->size;
	int i=0;//counter for loop
	for(i;i<rozmir;i++)
	{
		float A_x = ANarray->array[i].points[0].x;// tak zruchnishe provoditi rozrachunky
		float A_y = ANarray->array[i].points[0].y;
		float B_x = ANarray->array[i].points[1].x;
		float B_y = ANarray->array[i].points[1].y;
		float C_x = ANarray->array[i].points[2].x;
		float C_y = ANarray->array[i].points[2].y;
		float D_x = ANarray->array[i].points[3].x;
		float D_y = ANarray->array[i].points[3].y;
		
		float AC, BD;//variables for lenght of diagonals 
		
		AC = sqrt((C_x - A_x)*(C_x - A_x) + (C_y - A_y)*(C_y - A_y));
		
		BD = sqrt((D_x - B_x)*(D_x - B_x) + (D_y - B_y)*(D_y - B_y));
		
		struct dot vektor_ac;//create VEKTORS     ac     and    bd
		struct dot vektor_bd;
		
		vektor_ac.x = (C_x - A_x);//first coordinate of vektor ac
		vektor_ac.y = (C_y - A_y);//second coordinate of vektor ac
	 
	 	vektor_bd.x = (D_x - B_x);//first coordinate of vektor bd
		vektor_bd.y = (D_y - B_y);//second coordinate of vektor bd
	 	
	 	
		float ac_bd;//count the scalar derivative (dobutok) of vektors 		ac 		and 		bd
		ac_bd = ( (vektor_ac.x * vektor_bd.x) + (	vektor_ac.y * 	vektor_bd.y) );
		
		float cos_a;//cosinus  of wanted angle (ugol)
		cos_a = ac_bd/(AC*BD);
		
		float S;//variable for area
		S = (AC * BD) / (2 * cos_a);
		
		ANarray->array[i].area = S;
		
	}
	
}

void json_write( FILE *file, SquareArray *aList)
{
	int aSize = aList->size;
	int curr_size = aList->current_size;
	
	fprintf(file, "{\n\t\"size\" : %i,\n\t\"current_size\" : %i,\n\t\"array\" : [", aSize,curr_size);
	
	int i = 0;
	for(i;i<curr_size;i++)
	{
		fprintf(file, "\n\t\t{\n\t\t\"points\" : [");
		//A
		fprintf(file, "\n\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[0].x) , (aList->array[i].points[0].y) );
		//B
		fprintf(file, "\n\t\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[1].x) , (aList->array[i].points[1].y) );
		//C
		fprintf(file, "\n\t\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[2].x) , (aList->array[i].points[2].y) );
		//D
		fprintf(file, "\n\t\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[3].x) , (aList->array[i].points[3].y) );
		
		fprintf(file, "\n\t\t]\n\t\t\t\t\"area\" : % .2f\n\t\t},", (aList->array[i].area));
	}
	
	fflush(file);
	fclose(file);
}	

void writeSquareArrayInConsole(SquareArray *aList)//write an ARRAY of KVADRATS in console
{
	int aSize = aList->size;
	int curr_size = aList->current_size;
	
	printf("{\n\n\t\"size\" : %i,\n\t\"current_size\" : %i,\n\t\"array\" : [", aSize,curr_size);
	
	int i = 0;
	for(i;i<curr_size;i++)
	{
		printf( "\n\t\t{\n\t\t\"points\" : [");
		//A
		printf( "\n\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[0].x) , (aList->array[i].points[0].y) );
		//B
		printf( "\n\t\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[1].x) , (aList->array[i].points[1].y) );
		//C
		printf( "\n\t\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[2].x) , (aList->array[i].points[2].y) );
		//D
		printf( "\n\t\t\t\t{\n\t\t\t\t\"X\" : % .2f,\n\t\t\t\t\"Y\" : % .2f\n\t\t\t},",(aList->array[i].points[3].x) , (aList->array[i].points[3].y) );
		
		printf( "\n\t\t]\n\t\t\t\t\"area\" : % .2f\n\t\t},", (aList->array[i].area));
	}
	
}

	
float scan(int min, int max)// just scanf with checking on idiot
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
 

