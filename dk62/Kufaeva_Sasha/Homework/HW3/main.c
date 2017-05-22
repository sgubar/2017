#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	ParpipedList * theParpiped = createParpipedList(6);
	
    addParpipedCoordinates(theParpiped);
    addParpipedCoordinates(theParpiped);
    addParpipedCoordinates(theParpiped);
    addParpipedCoordinates(theParpiped);
    addParpipedCoordinates(theParpiped);
    
    
    FILE *theFile = fopen("json2.txt","w");
    
    printParpipedList(theParpiped);
    writeParpipedList(theFile,theParpiped);
    
    destroyParpipedList(theParpiped);
	
	return 0;
}
