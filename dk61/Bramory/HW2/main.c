#include <stdio.h>
#include <conio.h>
#include "tool.h"

int main() 
{
	float container = 0;
	
	FigureList *theList = createFigureList(5); 
	addCircle(theList, 1, 2, 3);
	addCircle(theList, 3, 2, 1);
	
	Circle myCircle = theList -> circles[1];
	printf("[X,Y] - [%i][%i]\n", myCircle.x, myCircle.y, myCircle.radius);
	printf("Radius - [%i] \n ", myCircle.radius);
	
	
	container = Square(myCircle.radius);
	printf("\nSquare = %.3f\n", container);

	destroyFigureList( theList );
		
	getch();
	return 0;
}
