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
    printf("Before sorting....\n");
    printParpipedList(theParpiped);
    writeParpipedList(theFile,theParpiped);
    
   // void bubbleSort(theParpiped);
    //void selectionSort(theParpiped);
    //void insertionSort(theParpiped); 
    
    
    printf("After sorting....\n");
     //bubbleSort(theParpiped);
    //(theParpiped);
    selectionSort(theParpiped);
    //insertionSort(theParpiped);
    printParpipedList(theParpiped);
    
    
    
    destroyParpipedList(theParpiped);
	
	return 0;
}



