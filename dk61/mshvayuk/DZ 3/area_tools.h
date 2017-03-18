#ifndef area_tools_h
#define area_tools_h

#include<stdio.h>

void kvadrat();

typedef struct dot {//struct for something with 2 coordinates  (x ; y)
	float x;		//coordinates X  and  Y
	float y;
} point;         

float scan();// just scanf with checking on idiot

void scan_dot( point *masiv);// scan X  and  Y  coordinates  of every our dot

float area( point *masiv); // it counts area of figure

void json_write( FILE *file, point *masiv);//write a dots into .JSON file


#endif /*area_tools_h*/


