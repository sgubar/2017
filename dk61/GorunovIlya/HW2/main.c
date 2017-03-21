#include <stdio.h>
#include "dk_tool.h"
#include <string.h>

int main()
{
	SphereList * theSphere = createSphereList(4);
	
	addSphere(theSphere, 2, 2, 2, 5);
	addSphere(theSphere, 3, 3, 3, 6);
	
	int x = enterParametersOfSphere();
	int y = enterParametersOfSphere();
	int z = enterParametersOfSphere();
	int radius = enterParametersOfSphere();
	
	addSphere(theSphere,x,y,z,radius);
	
	
	SpherePosition firstSphere = theSphere ->spheres[2];
	printf("X, Y, Z   -  %i, %i, %i and radius is %i: \n",firstSphere.xPosition ,firstSphere.yPosition ,firstSphere.zPosition,firstSphere.radius);
	
	float area = areaCalculation(&firstSphere);
	printf("The area of sphere is: %.3f", area);
	
	
	
	destroySphereList(theSphere);
	
	return 0;
	
}

