#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	ParpipedList * theParpiped = createParpipedList(2);
	
    addParpipedCoordinates(theParpiped);
    //addParpipedCoordinates(theParpiped);

//	ParpipedPoints firstParpiped = theParpiped->parpipeds[0];
//	
//	int area = areaCalculation(&firstParpiped);
//	printf("Area of parpiped %d\n",area);
    printParpipedList(theParpiped);
    
    destroyParpipedList(theParpiped);
	
	return 0;
}
