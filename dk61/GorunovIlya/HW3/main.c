#include <stdio.h>
#include "dk_tool.h"
#include <string.h>

int main()
{
	SphereList * theSphere = createSphereList(7);
	FILE * theFile = fopen("List.json","w");
	
	addSphere(theSphere, 2, 2, 2, 5);
	addSphere(theSphere, 3, 3, 3, 6);
	addSphere(theSphere, 4, 4, 4, 7);
	addSphere(theSphere, 5, 5, 5, 8);
	addSphere(theSphere, 6, 6, 6, 9);
	addSphere(theSphere, 7, 7, 7, 9);
	
	int x = enterParametersOfSphere();
	int y = enterParametersOfSphere();
	int z = enterParametersOfSphere();
	int radius = enterParametersOfSphere();
	addSphere(theSphere, x, y, z, radius);
	
	writeInFile(theFile,theSphere);
	
	SpherePosition firstSphere = theSphere ->spheres[6];
	printf("X, Y, Z   -  %i, %i, %i and radius is: %i;\n",firstSphere.xPosition ,firstSphere.yPosition ,firstSphere.zPosition,firstSphere.radius);
	
	float area = areaCalculation(&firstSphere);
	printf("The area of sphere is: %.3f;\n", area);
	
	
	
	destroySphereList(theSphere);
	
	return -1;
	
}

