#include <stdio.h>
#include "hw2.h"
#include <string.h>

int main()
{
	SphereList * Sphere = createSphereList(7);
	
	addSphere(Sphere, 2, 2, 2, 5);
	addSphere(Sphere, 3, 3, 3, 4);
	addSphere(Sphere, 5, 8, 5, 7);
	addSphere(Sphere, 1, 1, 0, 2);
	addSphere(Sphere, 6, 5, 4, 1);
	
	int a;
	for(a=0; a<5; a++)
	{	
		SpherePosition firstSphere = Sphere ->spheres[a];
		printf("Coordinate %i sphere -  [%i] [%i] [%i] and radius is: %i;\n",a+1,firstSphere.x ,firstSphere.y ,firstSphere.z,firstSphere.R);
		printf("The area of sphere is: %.3f;\n",  Squareareas(&firstSphere));
		printf("\n\n");
	}
	
	
	removeSphereList(Sphere);
	
	return -1;
	
}
