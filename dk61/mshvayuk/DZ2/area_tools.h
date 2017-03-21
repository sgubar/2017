#ifndef area_tools_h
#define area_tools_h

#include<stdio.h>

void kvadrat();

typedef struct dot {//struct for something with 2 coordinates  (x ; y)
	float x;		//coordinates X  and  Y
	float y;
} point;         


typedef struct tagSquare
{
	point points[4];
} Square;

typedef struct tagSquareArray
{
	Square *array;
	int size;
	int current_size;
} SquareArray;

SquareArray *square_array(int size);
void addSquareToList(SquareArray *aList, Square *aSquare);
void sort_SquareList(SquareArray *aList)
{
	for (Square *square in aList->array)
	{
		double area = area_square(square);
	}
}





double area_square(Square *aSquare);

float scan();// just scanf with checking on idiot

void scan_dot( point *masiv);// scan X  and  Y  coordinates  of every our dot

float area( point *masiv); // it counts area of figure


#endif /*area_tools_h*/


