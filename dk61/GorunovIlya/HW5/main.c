#include <stdio.h>
#include "dk_tool.h"
#include <string.h>

int main()
{
	SphereList * theSphere = createSphereList(8);
	FILE * theFile = fopen("List.json","w");
	
	addSphere(theSphere, 2, 2, 2, 8);
	addSphere(theSphere, 3, 3, 3, 4);
	addSphere(theSphere, 4, 4, 4, 6);
	addSphere(theSphere, 5, 5, 5, 2);
	addSphere(theSphere, 6, 6, 6, 9);
	addSphere(theSphere, 7, 7, 7, 7);
	
	printf("Enter X coordinate: ");
	int x = enterParametersOfSphere();
	printf("Enter Y coordinate: ");
	int y = enterParametersOfSphere();
	printf("Enter Z coordinate: ");
	int z = enterParametersOfSphere();
	printf("Enter Radius: ");
	int radius = enterParametersOfSphere();
	
	addSphere(theSphere, x, y, z, radius);
	
	writeInFile(theFile,theSphere);
	fprintf(theFile,"\n----------------After sorting------------------------\n");
	
	
	SpherePosition firstSphere = theSphere ->spheres[6];
	printf("X, Y, Z   -  %i, %i, %i and radius is: %i;\n",firstSphere.xPosition ,firstSphere.yPosition ,firstSphere.zPosition,firstSphere.radius);
	
	float area = areaCalculation(&firstSphere);
    printf("The area of sphere is: %.3f;\n", area);


    printf("\nBefore sorting...\n");
	writeListOnScreen(theSphere);
	printf("----------------------------------------------\n");
	//bubbleSort(theSphere);
	//selectionSort(theSphere);
	//insertionSort(theSphere);
	
	//bubbleSort2(theSphere);
	//selectionSort2(theSphere);
	//insertionSort2(theSphere);
	
	shellSort(theSphere);
	
	printf("After sorting....\n");
	writeListOnScreen(theSphere);
	writeInFile(theFile,theSphere);
	
	
	printf("Enter a radius for binary Search: ");
	int radiusForBinarySearch = enterParametersOfSphere();
	
	int theResult = binarySearch(theSphere,radiusForBinarySearch);
	SpherePosition binarySearchSphere = theSphere->spheres[theResult];
	writeStructAfterBinarySearch(&binarySearchSphere);
	
	destroySphereList(theSphere);
	
	fflush(theFile);
	fclose(theFile);
	return 1;
	
}


